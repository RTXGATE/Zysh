#pragma once
#include "built-in/builtin.hpp"

class Shell
{
private:
	Builtin builtin;
	void printPrompt();
public:
	int Run();
};
