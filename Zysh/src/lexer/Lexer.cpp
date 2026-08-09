#include "Lexer.hpp"

#include <utility>

void Lexer::appendLiteral(char c, QuoteContext context)
{
	if (m_segments.empty()|| m_segments.back().context != context)
	{
		TokenSegment segment;
		segment.context = context;
		m_segments.emplace_back(std::move(segment));
	}

	SegmentPart part;
	part.type = SegmentPartType::Literal;
	part.value = c;

	m_segments.back().parts.emplace_back(part);
}

void Lexer::appendLiteral(const std::string& text,QuoteContext context)
{
	for (char c : text)
	{
		appendLiteral(c,context);
	}
}


void Lexer::appendEscape(char c, QuoteContext context)
{
	if (m_segments.empty() || m_segments.back().context != context)
	{
		TokenSegment segment;
		segment.context = context;
		m_segments.emplace_back(std::move(segment));
	}
	SegmentPart part;
	part.type = SegmentPartType::Escape;
	part.value= c;

	m_segments.back().parts.emplace_back(part);
}

void Lexer::consumeEscape(const std::string& input, std::string& word)
{
	++m_position;

    	if (m_position >= input.size())
    	{
        	m_escapePending = true;
        	return;
    	}

    	const char escaped = input[m_position];

    	/*
     	* Backslash + newline = line continuation.
     	*/
    	if (escaped == '\n')
    	{
        	++m_position;
        	m_escapePending = false;
        	return;
    	}

	const QuoteContext context = (m_state == State::DoubleQuote) ? QuoteContext::DoubleQuoted : QuoteContext::Unquoted;

    	/*
     	* Double-quoted context.
     	*/
	appendEscape(escaped , context);

	word += '\\';
	word += escaped;

    	++m_position;
    	m_escapePending = false;
}

void Lexer::processCharacter(char c)
{
	if (m_state == State::SingleQuote)
    	{
        	if (c == '\'')
        	{
            		m_state = State::Normal;
        	}
        	else
        	{
            		m_currentWord += c;
        	}

        return;
    	}

    	if (m_state == State::DoubleQuote)
    	{
        	if (c == '"')
        	{
            		m_state = State::Normal;
        	}
        	else
        	{
            		m_currentWord += c;
        	}

        return;
    	}

    	m_currentWord += c;
}

void Lexer::resetWord()
{
    	m_currentWord.clear();
	m_segments.clear();
}

LexerStatus Lexer::getStatus() const
{
	if (m_escapePending)
    	{
        	return LexerStatus::TrailingEscape;
    	}

    	if (m_state == State::SingleQuote)
    	{
        	return LexerStatus::UnterminatedSingleQuote;
    	}

    	if (m_state == State::DoubleQuote)
    	{
        	return LexerStatus::UnterminatedDoubleQuote;
    	}

    	return LexerStatus::Complete;
}

bool Lexer::isOperatorStart(const std::string& input) const
{
    	if (m_position >= input.size())
    	{
        	return false;
    	}

    	const char c = input[m_position];

    	return c == '|' || c == '<' ||c == '>' || c == '1' || c == '2';
}

Token Lexer::readOperator(const std::string& input)
{
    	Token token;

    	/*
     	* 1>&2
     	*/
    	if (m_position + 3 < input.size() && input[m_position] == '1' && input[m_position + 1] == '>' && input[m_position + 2] == '&' && input[m_position + 3] == '2')
   	{
        	token.type = TokenType::REDIRECT_FD;
        	token.text = "1>&2";

        	m_position += 4;
        	return token;
    	}

    	/*
     	* 2>>
     	*/
    	if (m_position + 2 < input.size() && input[m_position] == '2' && input[m_position + 1] == '>' && input[m_position + 2] == '>')
    	{
        	token.type = TokenType::REDIRECT_ERR_APPEND;
        	token.text = "2>>";

        	m_position += 3;
        	return token;
    	}

    	/*
     	* 2>
     	*/
    	if (m_position + 1 < input.size() && input[m_position] == '2' && input[m_position + 1] == '>')
    	{
       		token.type = TokenType::REDIRECT_ERR;
        	token.text = "2>";

       		m_position += 2;
        	return token;
    	}

    	/*
     	* >>
     	*/
    	if (m_position + 1 < input.size() && input[m_position] == '>' && input[m_position + 1] == '>')
    	{
        	token.type = TokenType::APPEND;
        	token.text = ">>";

       		m_position += 2;
        	return token;
    	}

    	switch (input[m_position])
    	{
        	case '|':
            		token.type = TokenType::PIPE;
            		token.text = "|";
            		++m_position;
            		return token;

        	case '<':
            		token.type = TokenType::REDIRECT_IN;
            		token.text = "<";
            		++m_position;
            		return token;

        	case '>':
            		token.type = TokenType::REDIRECT_OUT;
            		token.text = ">";
            		++m_position;
            		return token;

        	default:
            		return token;
    	}
}

std::string Lexer::readWord(const std::string& input)
{
	resetWord();
	while (m_position < input.size())
	{
		const char c = input[m_position];

		if (m_escapePending)
		{
			consumeEscape(input, m_currentWord);
			continue;
		}

		/*
	 	* NORMAL
	 	*/
		if (m_state == State::Normal)
		{
			if (c == ' ' ||c == '\t' || c == '\n')
			{
				break;
			}

			if (isOperatorStart(input))
			{
				break;
			}

			if (c == '\'')
			{
				m_state = State::SingleQuote;
				++m_position;
				continue;
			}

			if (c == '"')
			{
				m_state = State::DoubleQuote;
				++m_position;
				continue;
			}

			if (c == '\\')
			{
				consumeEscape(input, m_currentWord);
				continue;
			}

			m_currentWord += c;

			appendLiteral(c, QuoteContext::Unquoted);

			++m_position;
			continue;
		}

		/*
	 	* SINGLE QUOTE
	 	*/
		if (m_state == State::SingleQuote)
		{
			if (c == '\'')
			{
				m_state = State::Normal;
				++m_position;
				continue;
			}

			m_currentWord += c;

			appendLiteral(c,QuoteContext::SingleQuoted);

			++m_position;
			continue;
		}

		/*
	 	* DOUBLE QUOTE
	 	*/
		if (m_state == State::DoubleQuote)
		{
			if (c == '"')
			{
				m_state = State::Normal;
				++m_position;
				continue;
			}

			if (c == '\\')
			{
				consumeEscape(input, m_currentWord);
				continue;
			}

			m_currentWord += c;

			appendLiteral(c, QuoteContext::DoubleQuoted);

			++m_position;
			continue;
		}
	}

	return m_currentWord;
}

LexerResult Lexer::Tokenize(const std::string& input)
{
    	LexerResult result;

    	reset();

    	while (m_position < input.size())
    	{
        	const char c = input[m_position];

        	if (c == ' ' || c == '\t' || c == '\n')
        	{
            		++m_position;
            		continue;
        	}

        	if (isOperatorStart(input))
        	{
            		result.tokens.emplace_back(
                	readOperator(input)
            	);

            	continue;
	}

        std::string word = readWord(input);

        	if (!word.empty())
        	{
        		Token token;

            		token.type = TokenType::WORD;
            		token.text = word;
            		token.segments = std::move(m_segments);

            		result.tokens.emplace_back(std::move(token));

            		m_segments.clear();
        	}
	}

    	result.status = getStatus();

    	return result;
}

void Lexer::reset()
{
    	m_position = 0;
    	m_state = State::Normal;
    	m_escapePending = false;
    	m_currentWord.clear();
    	m_segments.clear();
}
