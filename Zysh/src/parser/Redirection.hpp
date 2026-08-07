#pragma once

#include <string>

enum class RedirectType
{
	INPUT,
	OUTPUT,
	APPEND,
	ERROR,
	ERROR_APPEND,
	FD_DUP
};

struct Redirection
{
	RedirectType type;
	std::string file;

	int sourceFD = -1;
	int targetFD = -1;
};

