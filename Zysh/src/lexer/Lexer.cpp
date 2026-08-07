#include "Lexer.hpp"

std::vector<Token> Lexer::Tokenize(const std::string& input)
{
	std::vector<Token> tokens;
	m_position = 0; 
	while (m_position < input.size())
	{
		std::string word;
		if (input[m_position] == ' ')
		{
			++m_position;
			continue;
		}

		if (input[m_position] == '|')
		{
			Token token;
			token.type = TokenType::PIPE;
			token.text = "|";

			tokens.push_back(token);

			m_position++;
			continue;
		}

		if (input[m_position] == '>')
		{
			Token token;

			if (m_position +1 < input.size() && input[m_position +1] == '>')
			{
				token.type = TokenType::APPEND;
				token.text = ">>";
				m_position += 2;
			}

			else
			{
				token.type = TokenType::REDIRECT_OUT;
				token.text = ">";
				m_position++;
			}

			tokens.push_back(token);
			continue;
		}

		if (input[m_position]== '<')
		{
			Token token;
			token.type = TokenType::REDIRECT_IN;
			token.text = "<";

			tokens.push_back(token);
			m_position++;
			continue;
		}
		if (m_position + 3 < input.size() && input[m_position] == '1' && input[m_position + 1] == '>' && input[m_position + 2] == '&' && input[m_position + 3] == '2')
		{
    			Token token;

    			token.type = TokenType::REDIRECT_FD;
    			token.text = "1>&2";

    			tokens.push_back(token);

    			m_position += 4;
    			continue;
		}

		if (input[m_position] == '2' && m_position + 2 < input.size() && input[m_position + 1] == '>' && input[m_position + 2] == '>')
		{
			Token token;

			token.type = TokenType::REDIRECT_ERR_APPEND;
			token.text = "2>>";

			tokens.push_back(token);

			m_position += 3;
			continue;
		}

		if (input[m_position] == '2' && m_position + 1 < input.size() && input[m_position + 1] == '>')
		{
			Token token;

			token.type = TokenType::REDIRECT_ERR;
			token.text = "2>";

			tokens.push_back(token);

			m_position += 2;
			continue;
		}

		while (m_position < input.size() && input[m_position] != ' ')
		{
			word += input[m_position];
			++m_position;
		}

		Token token;
		token.type = TokenType::WORD;
		token.text = word;
		tokens.emplace_back(std::move(token));
	}
	return tokens;
}
