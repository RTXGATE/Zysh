#pragma once

#include <vector>
#include <string>
#include "../Token/Token.hpp"

class Lexer
{
private:

	size_t m_position;

public:
	std::vector<Token> Tokenize(const std::string& input);
};
