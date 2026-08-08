#pragma once
#include "built-in/builtin.hpp"
#include "lexer/Lexer.hpp"

class Shell
{
private:
	Builtin builtin;
	void printPrompt();
	void printContinuationPrompt(LexerStatus status);
	LexerStatus status;


public:
	int Run();
};
