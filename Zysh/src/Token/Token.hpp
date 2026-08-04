#pragma once

#include <string>

enum class TokenType {
	WORD,
	END
};

struct Token
{
	TokenType type;
	std::string text;
};
