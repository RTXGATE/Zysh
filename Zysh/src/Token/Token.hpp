#pragma once

#include <string>

enum class TokenType {
	WORD,
	PIPE,
	END
};

struct Token
{
	TokenType type;
	std::string text;
};
