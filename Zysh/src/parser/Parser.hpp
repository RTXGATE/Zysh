#pragma once

#include <vector>
#include "command.hpp"
#include "../Token/Token.hpp"
#include <iostream>

class Parser
{
public:
	Command Parse(const std::vector<Token>& tokens);
	Pipeline ParsePipeline(const std::vector<Token>& tokens);
	std::string EvaluateToken(const Token& token);

private:
	size_t m_position = 0;
};
