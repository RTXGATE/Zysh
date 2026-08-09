#pragma once
#include <string>
#include <vector>
#include "Redirection.hpp"

struct Command
{
	std::string name;
	std::vector<std::string> args;

	std::vector<Redirection> redirects;
};

struct Pipeline
{
	std::vector<Command> commands;
};


