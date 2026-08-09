#include "Shell.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"
#include "executor/Executor.hpp"

#include <iostream>
#include <string>
#include <vector>

void Shell::printPrompt()
{
    std::cout << "Zysh> ";
}

void Shell::printContinuationPrompt(
    LexerStatus status)
{
    switch (status)
    {
        case LexerStatus::UnterminatedDoubleQuote:
            std::cout << "dquote> ";
            break;

        case LexerStatus::UnterminatedSingleQuote:
            std::cout << "quote> ";
            break;

        case LexerStatus::TrailingEscape:
            std::cout << "escape> ";
            break;

        case LexerStatus::Complete:
            printPrompt();
            break;
    }
}

int Shell::Run()
{
    Lexer lexer;
    Parser parser;
    Executor executor;

    std::string commandBuffer;

    LexerStatus continuationStatus =
        LexerStatus::Complete;

    while (true)
    {
        /*
         * Prompt
         */
        if (continuationStatus ==
            LexerStatus::Complete)
        {
            printPrompt();
        }
        else
        {
            printContinuationPrompt(
                continuationStatus
            );
        }

        std::string input;

        if (!std::getline(
                std::cin,
                input))
        {
            std::cout << std::endl;
            break;
        }

        /*
         * Add the new line to the complete command.
         */
        if (!commandBuffer.empty())
        {
            commandBuffer += '\n';
        }

        commandBuffer += input;

        /*
         * Empty command at the normal prompt.
         */
        if (continuationStatus ==
                LexerStatus::Complete &&
            input.empty())
        {
            commandBuffer.clear();
            continue;
        }

        /*
         * Always lex the COMPLETE command buffer.
         */
        LexerResult lexerResult =
            lexer.Tokenize(commandBuffer);

        /*
         * Command is incomplete.
         */
        if (lexerResult.status !=
            LexerStatus::Complete)
        {
            continuationStatus =
                lexerResult.status;

            continue;
        }

        /*
         * Command is complete.
         */
        continuationStatus =
            LexerStatus::Complete;

        const std::vector<Token>& tokens =
            lexerResult.tokens;

        if (tokens.empty())
        {
            commandBuffer.clear();
            continue;
        }

        /*
         * Detect pipeline.
         */
        bool hasPipe = false;

        for (const auto& token : tokens)
        {
            if (token.type ==
                TokenType::PIPE)
            {
                hasPipe = true;
                break;
            }
        }

        /*
         * Execute.
         */
        if (hasPipe)
        {
            Pipeline pipeline =
                parser.ParsePipeline(tokens);

            executor.executePipeline(
                pipeline
            );
        }
        else
        {
            Command command =
                parser.Parse(tokens);

            BuiltinResult result =
                builtin.Execute(command);

            if (result ==
                BuiltinResult::Exit)
            {
                break;
            }

            if (result ==
                BuiltinResult::NotFound)
            {
                executor.execute(command);
            }
        }

        /*
         * Command has been consumed.
         * Start a completely new command.
         */
        commandBuffer.clear();
        lexer.reset();
    }

    return 0;
}
