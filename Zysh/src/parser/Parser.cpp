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

Pipeline Parser::ParsePipeline(const std::vector<Token>& tokens)
{
	Pipeline pipeline;
	Command current;

	for (const auto& token : tokens)
	{
		if (token.type == TokenType::WORD)
		{
			if (current.name.empty())
			{
				current.name = token.text;
			}
			else
			{
			current.args.push_back(token.text);
			}
		}
		else if (token.type == TokenType::PIPE)
		{
			pipeline.commands.push_back(current);
			current = Command();
		}
	}

	if (!current.name.empty())
	{
		pipeline.commands.push_back(current);
	}
	return pipeline;
}
