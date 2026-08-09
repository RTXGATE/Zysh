#include "Expander.hpp"

std::string Expander::Expand(const Token& token) const
{
    if (token.type != TokenType::WORD)
    {
        return token.text;
    }

    std::string result;

    for (const TokenSegment& segment : token.segments)
    {
        result += expandSegment(segment);
    }

    return result;
}

std::string Expander::expandSegment(
    const TokenSegment& segment) const
{
    switch (segment.context)
    {
        case QuoteContext::SingleQuoted:
        {
            /*
             * Single quotes preserve their contents literally.
             */
            return segment.text;
        }

        case QuoteContext::DoubleQuoted:
        {
            /*
             * For now, double-quoted escape processing
             * is handled separately.
             */
            return expandEscape(segment.text);
        }

        case QuoteContext::Unquoted:
        {
            return expandEscape(segment.text);
        }
    }

    return segment.text;
}

std::string Expander::expandEscape(
    const std::string& text) const
{
    std::string result;

    for (std::size_t i = 0; i < text.size(); ++i)
    {
        if (text[i] != '\\')
        {
            result += text[i];
            continue;
        }

        /*
         * A trailing backslash should never normally
         * reach this layer because Lexer detects it.
         */
        if (i + 1 >= text.size())
        {
            result += '\\';
            continue;
        }

        const char escaped = text[++i];

        switch (escaped)
        {
            case 'n':
                result += '\n';
                break;

            case 't':
                result += '\t';
                break;

            case 'r':
                result += '\r';
                break;

            case '\\':
                result += '\\';
                break;

            case '"':
                result += '"';
                break;

            default:
                /*
                 * Unknown escape:
                 * preserve it instead of silently destroying data.
                 */
                result += '\\';
                result += escaped;
                break;
        }
    }

    return result;
}
