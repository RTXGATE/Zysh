#include "builtin.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

BuiltinResult Builtin::Execute(const Command& command)
{
	if (command.name == "exit")
	{
		std::cout << "Exiting Zysh shell![returned 0]" << std::endl;
		return BuiltinResult::Exit;
	}

	if (command.name == "cd")
	{
		if (command.args.empty())
		{
			std::cerr << "cd: missing operands\n" <<std::endl;
			return BuiltinResult::NotFound;
		}
		else
		{
			if (chdir(command.args[0].c_str()) == -1)
			{
				perror("cd");
				return BuiltinResult::Executed;
			}
			else
			{
				return BuiltinResult::Executed;
			}
		}
	}
	if (command.name == "export"){
		if (command.args.empty())
		{
			std::cerr << "export: missing argument\n" << std::endl;
			return BuiltinResult::Executed;
		}
		std::string arg = command.args[0];

		size_t pos = arg.find("=");
		
		if (pos == std::string::npos)
		{
			std::cerr << "export: invalid format" << std::endl;
			return BuiltinResult::Executed;
		}
		std::string name = arg.substr(0 , pos);
		std::string value =arg.substr(pos + 1);
		setenv(name.c_str(), value.c_str(), 1);
		return BuiltinResult::Executed;
	}
	if (command.name == "unset")
	{
		if (command.args.empty())
		{
			std::cerr << "unset: missing argument\n" << std::endl;
			return BuiltinResult::Executed;
		}

		for (const auto& arg : command.args)
		{
			if (unsetenv(arg.c_str()) == -1)
			{
				perror("unset");
			}
		}
		return BuiltinResult::Executed;
	}
	return BuiltinResult::NotFound;
}
