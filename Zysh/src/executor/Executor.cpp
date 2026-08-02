#include "Executor.hpp"
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
#include <iostream>

int Executor::execute(const Command& command)
{
	pid_t pid = fork();
	
	if (pid == -1)
	{
		std::cerr << "Error in fork\n[Returned 1 exit code" << std::endl;
		return 1;
	}
	if (pid ==0)
	{
		std::vector<char*> argv;

		argv.push_back(const_cast<char*>(command.name.c_str()));

		for (const auto& arg : command.args)
		{
			argv.push_back(const_cast<char*>(arg.c_str()));
		}

		argv.push_back(nullptr);

		execvp(command.name.c_str(), argv.data());
		std::cerr <<"command not found" << std::endl;

		return 1;
	}
	else 
	{
		waitpid(pid , nullptr, 0);
	}
	return 0;
}
