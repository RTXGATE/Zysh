#pragma once

#include <string>

enum class TokenType {
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_ERR,
	REDIRECT_ERR_APPEND,
	REDIRECT_FD,
	APPEND,
	END
};

struct Token
{
	TokenType type;
	std::string text;
};
