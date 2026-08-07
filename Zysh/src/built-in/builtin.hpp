#pragma once
#include "../parser/command.hpp"

enum class BuiltinResult
{
        NotFound,
        Executed,
        Exit
};



class Builtin
{
public:
	BuiltinResult Execute(const Command& command);
};


