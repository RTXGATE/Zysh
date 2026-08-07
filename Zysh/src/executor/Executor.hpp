#pragma once
#include "../parser/command.hpp"
#include <vector>
#include <array>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <signal.h>
#include <fcntl.h>

class Executor
{
public:
	int execute(const Command& command);
	int executePipeline(const Pipeline& pipeline);
private:
	void runCommand(const Command& command);
	void closePipes(std::vector<std::array<int , 2>>& pipes);
	bool createPipes(std::vector<std::array<int , 2>>& pipes, int count);
	bool setupChildIO(int index, int count, std::vector<std::array<int, 2>>& pipes);
	bool setupRedirections(const Command& command);
};
