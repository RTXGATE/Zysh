#include "../lexer/Lexer.hpp"

#include <iostream>
#include <random>
#include <string>

int main()
{
    Lexer lexer;

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
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception found!\n";
            std::cerr << "Input: " << input << "\n";
            std::cerr << e.what() << "\n";
            return 1;
        }

        if (i % 10000 == 0)
        {
            std::cout << "Tested: " << i << "\n";
        }
    }

    std::cout << "Fuzz PASS\n";
    return 0;
}
