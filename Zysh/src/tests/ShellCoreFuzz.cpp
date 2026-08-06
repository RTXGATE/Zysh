#include "../lexer/Lexer.hpp"
#include "../parser/Parser.hpp"
#include "../built-in/builtin.hpp"

#include <iostream>
#include <random>
#include <string>

int main()
{
    Lexer lexer;
    Parser parser;
    Builtin builtin;

    std::mt19937 rng(std::random_device{}());

    const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()_+-=[]{};:'\",.<>/?\\| ";

    for (int i = 0; i < 100000; i++)
    {
        std::string input;

        int length = rng() % 512;

        for (int j = 0; j < length; j++)
        {
            input += chars[rng() % chars.size()];
        }

        try
        {
            auto tokens = lexer.Tokenize(input);
            auto command = parser.Parse(tokens);

            auto result = builtin.Execute(command);
            (void)result;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Shell core crash!\n";
            std::cerr << "Input:\n";
            std::cerr << input << "\n";
            std::cerr << e.what() << "\n";
            return 1;
        }

        if (i % 10000 == 0)
        {
            std::cout << "Tested: " << i << "\n";
        }
    }

    std::cout << "Shell Core Fuzz PASS\n";

    return 0;
}
