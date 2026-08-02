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
