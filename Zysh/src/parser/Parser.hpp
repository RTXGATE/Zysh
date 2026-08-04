#pragma once

#include <vector>
#include "command.hpp"
#include "Token/Token.hpp"

class Parser
{
public:
	Command Parse(const std::vector<Token>& tokens);

private:
	size_t m_position = 0;
};
