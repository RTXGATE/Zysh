#pragma once
#include <string>
#include "../Token/Token.hpp"

class Expender
{
public:
	std::string Expand(const Token& token) const;

private:
	std::string expendSegment(const TokenSegment& segment) const;

	std::string expendEscape(const std::string& text) const;
};
