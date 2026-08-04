#include "Parser.hpp"

Command Parser::Parse(const std::vector<Token>& tokens)
{
	Command cmd;
	m_position = 0;

	if (tokens.empty())
	{
		return cmd;
	}
	cmd.name = tokens[m_position].text;
	m_position++;

	while (m_position < tokens.size())
	{
		cmd.args.push_back(tokens[m_position].text);
		m_position++;
	}
	return cmd;
}
