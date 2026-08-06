#include <signal.h>
#include "Executor.hpp" // + vector + array
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

bool Executor::createPipes(std::vector<std::array<int , 2>>& pipes, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (pipe(pipes[i].data()) == -1)
		{
			perror("pipe");
			return false;
		}
	}
	return true;
}

bool Executor::setupChildIO(int index, int count, std::vector<std::array<int, 2>>& pipes)
{
	if (index > 0)
	{
		if (dup2(pipes[index -1][0], STDIN_FILENO) == -1)
		{
			perror("dup2 stdin");
			return false;
		}
	}

	if (index < count - 1)
	{
		if (dup2(pipes[index][1], STDOUT_FILENO) == -1)
		{
			perror("dup2 stdout");
			return false;
		}
	}
	return true;
}

void Executor::closePipes(std::vector<std::array<int, 2>>& pipes)
{
	for (auto& p : pipes)
	{
		close(p[0]);
		close(p[1]);
	}
}

int Executor::execute(const Command& command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		std::cerr << "Error in fork\n[Returned 1 exit code]" << std::endl;
		return 1;
	}
	if (pid ==0)
	{
		signal(SIGINT, SIG_DFL);
		runCommand(command);
		_exit(127);
	}
	else 
	{
		struct sigaction sa{};
		sa.sa_handler = SIG_IGN;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGINT, &sa, nullptr);

		int status;
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return 1;
		}

		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status);
		}

		if (WIFSIGNALED(status))
		{
			std::cout << std::endl;
			return 128 + WTERMSIG(status);
		}
		return 1;
	}
}


int Executor::executePipeline(const Pipeline& pipeline)
{
	if (pipeline.commands.empty())
	{
		return 1;
	}

	int n = pipeline.commands.size();

	std::vector<std::array<int , 2>>pipes(n - 1);

	if (!createPipes(pipes, n-1))
	{
		return 1;
	}


	std::vector<pid_t> children;

	for (int i = 0; i < n; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			closePipes(pipes);
			return 1;
		}
		if (pid == 0)
		{
			if (!setupChildIO(i, n, pipes))
			{
				_exit(127);
			}

			closePipes(pipes);

		runCommand(pipeline.commands[i]);
		_exit(127);
		}
	children.push_back(pid);
	}

	closePipes(pipes);

	for (pid_t pid : children)
	{
		waitpid(pid, nullptr, 0);
	}
	return 0;
}

void Executor::runCommand(const Command& command)
{
	std::vector<char*> argv;

	argv.push_back(const_cast<char*>(command.name.c_str()));

	for (const auto& arg : command.args)
	{
		argv.push_back(const_cast<char*>(arg.c_str()));
	}

	argv.push_back(nullptr);
	execvp(command.name.c_str(), argv.data());
	std::cerr << "Zysh:" << command.name << ": command not found" << std::endl;
	_exit(127);
}
