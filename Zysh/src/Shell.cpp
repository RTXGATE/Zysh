#include "Shell.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"
#include "executor/Executor.hpp"
#include <cstring>
#include <vector>

extern "C" long prt_str(const char* str);
extern "C" long read_string(char* buffer, long max_len);

void Shell::printPrompt()
{
	prt_str("Zysh> ");
}

int Shell::Run()
{
	char buffer[256];
	Lexer lexer;
	Parser parser;
	Executor executor;

	while (true)
	{
		printPrompt();
		memset(buffer, 0 ,sizeof(buffer));    //for cleanin buffer
		long count = read_string(buffer , sizeof(buffer));
		
		if (count < 0){
			break;
		}

	std::vector<Token> tokens = lexer.Tokenize(std::string(buffer));
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
	return 0;
}
