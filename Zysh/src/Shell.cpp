#include "Shell.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"
#include "executor/Executor.hpp"
#include <vector>
#include <iostream>

void Shell::printPrompt()
{
	std::cout << "Zysh> ";
}

int Shell::Run()
{
	Lexer lexer;
	Parser parser;
	Executor executor;

	while (true)
	{
		printPrompt();
		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			break;
		}

		if (input.empty()){
			continue;
		}


	std::vector<Token> tokens = lexer.Tokenize(input);

	bool hasPipe = false;

	for (const auto& token : tokens)
	{
		if (token.type == TokenType::PIPE)
		{
			hasPipe = true;
			break;
		}
	}

	if (hasPipe)
	{
		Pipeline pipeline = parser.ParsePipeline(tokens);
		executor.executePipeline(pipeline);
	}
	else
	{
		Command command = parser.Parse(tokens);
		BuiltinResult result = builtin.Execute(command);

		if (result == BuiltinResult::Exit)
		{
			break;
		}

		if (result == BuiltinResult::NotFound)
		{
			executor.execute(command);
		}
	}

	}
	return 0;
}

