#pragma once

#include <string>
#include <vector>

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

enum class SegmentPartType
{
	Literal,
	Escape
};

struct SegmentPart
{
	SegmentPartType type;
	char value;
};

enum class QuoteContext
{
	Unquoted,
	SingleQuoted,
	DoubleQuoted
};

struct TokenSegment
{
	std::vector<SegmentPart> parts;
	QuoteContext context = QuoteContext::Unquoted;
};

struct Token
{
	TokenType type;
	std::string text;
	std::vector<TokenSegment> segments;
};
