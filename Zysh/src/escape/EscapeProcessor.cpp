#include "EscapeProcessor.hpp"

char EscapeProcessor::Decode(char c)
{
	switch (c)
	{
		case 'a': return '\a';
		case 'b': return '\b';
		case 'f': return '\f';
		case 'n': return '\n';
		case 'r': return '\r';
		case 't': return '\t';
		case 'v': return '\v';
		case '\\': return '\\';
		case '\'': return '\'';
		case '"':
			return '"';

		default:
			return c;
	}
}

std::string EscapeProcessor::Decode(const std::string& text)
{
	std::string result;
	result.reserve(text.size());

	for (std::size_t i = 0; i < text.size(); ++i)
	{
		if (text[i] != '\\')
		{
			result += text[i];
			continue;
		}
		result += Decode(text[++i]);
	}

	return result;
}
