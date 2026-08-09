#pragma once

#include <string>

class EscapeProcessor
{
public:
	static char Decode(char c);
	static std::string Decode(const std::string& text);
};
