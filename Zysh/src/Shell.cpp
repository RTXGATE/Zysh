#include "Shell.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"
#include "executor/Executor.hpp"
#include <cstring>

extern "C" long prt_str(const char* str);
extern "C" long read_string(char* buffer, long max_len);
int Shell::Run()
{
	char buffer[256];
	Lexer lexer;
	Parser parser;
	Executor executor;

	while (true)
	{
		memset(buffer, 0 ,sizeof(buffer));    //for cleanin buffer
		long count = read_string(buffer , sizeof(buffer));
		
		if (count < 0){
			break;
		}

		if (strcmp(buffer , "exit")== 0)
		{
			break;
		}
	std::vector<Token> tokens = lexer.Tokenize(std::string(buffer));
	Command command = parser.Parse(tokens);
	executor.execute(command);
	}
	return 0;
}
