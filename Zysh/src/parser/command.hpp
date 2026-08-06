#pragma once
#include <string>
#include <vector>

struct Command
{
	std::string name;
	std::vector<std::string> args;
};

struct Pipeline 
{
	std::vector<Command> commands;
};


