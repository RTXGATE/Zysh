#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "../Token/Token.hpp"

enum class LexerStatus
{
    Complete,
    UnterminatedSingleQuote,
    UnterminatedDoubleQuote,
    TrailingEscape
};

struct LexerResult
{
    LexerStatus status = LexerStatus::Complete;
    std::vector<Token> tokens;
};

class Lexer
{
private:
    enum class State
    {
        Normal,
        SingleQuote,
        DoubleQuote
    };

    std::size_t m_position = 0;

    std::vector<TokenSegment> m_segments;

    State m_state = State::Normal;
    bool m_escapePending = false;

    std::string m_currentWord;

    std::string readWord(
        const std::string& input
    );

    void consumeEscape(
        const std::string& input,
        std::string& word
    );

    void processCharacter(char c);

    LexerStatus getStatus() const;

    void resetWord();

    void appendSegment(const std::string& text,QuoteContext context);

    	bool isOperatorStart(const std::string& input) const;

    	Token readOperator(const std::string& input);

	void appendLiteral(char c, QuoteContext context);

	void appendLiteral(const std::string& text, QuoteContext context);

	void appendEscape(char c, QuoteContext context);

public:
    LexerResult Tokenize(
        const std::string& input
    );

    void reset();
};
