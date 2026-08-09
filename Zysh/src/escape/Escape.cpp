#include "Escape.hpp"

std::string Escape::Expend(const std::string& input)
{
	std::string output;
	output.reserve(input.size());

	for (std::size_t i = 0; i < input.size(); ++i)
	{
		const char c = input[i];

		if (c != '\\')
		{
			output += c;
			continue;
		}

		if (i + 1 >= input.size())
		{
			output += '\\';
			continue;
		}

		const char escaped = input[++i];

		switch (escaped)
		{
			case 'n':
				output += '\n';
				break;
			case 't':
				output += '\t';
				break;
			case 'r':
				output += '\r';
				break;
			case 'b':
				output += '\b';
				break;
			case 'a':
				output += '\a';
				break;
			case 'v':
				output += '\v';
				break;
			case '"':
				output += '"';
				break;
			case '\\':
				output += '\\';
				break;
			case '\'':
				output += '\'';
				break;
			default:
				output += '\\';
				output += escaped;
				break;

		}
	}

	return output;
}
