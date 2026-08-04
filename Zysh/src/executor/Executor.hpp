#pragma once
#include "parser/command.hpp"

class Executor
{
public:
	int execute(const Command& command);
};
