#include "Parser.hpp"
#include "command.hpp"

Command Parser::Parse(const std::vector<Token>& tokens)
{
	Command cmd;
	m_position = 0;

	if (tokens.empty())
	{
		return cmd;
	}
	cmd.name = tokens[m_position].text;
	m_position++;

	while (m_position < tokens.size())
	{
		const auto& token = tokens[m_position];

		if (token.type == TokenType::WORD)
		{
			cmd.args.push_back(token.text);
		}


		else if (token.type == TokenType::REDIRECT_IN)
		{
			m_position++;
			if (m_position < tokens.size())
			{
				Redirection redirect;

				redirect.type = RedirectType::INPUT;
				redirect.file = tokens[m_position].text;

				cmd.redirects.push_back(redirect);
			}
		}

		else if (token.type == TokenType::REDIRECT_OUT)
		{
			m_position++;

			if (m_position < tokens.size())
			{
				Redirection redirect;

				redirect.type = RedirectType::OUTPUT;
				redirect.file = tokens[m_position].text;
				cmd.redirects.push_back(redirect);
			}
		}

		else if (token.type == TokenType::REDIRECT_ERR_APPEND)
		{
			if (m_position + 1 < tokens.size())
			{
				Redirection redirect;

				redirect.type = RedirectType::ERROR_APPEND;
				redirect.file = tokens[++m_position].text;

				cmd.redirects.push_back(redirect);
			}
		}

		else if (token.type == TokenType::REDIRECT_ERR)
		{
			if (m_position + 1 < tokens.size())
			{
				Redirection redirect;

				redirect.type = RedirectType::ERROR;
				redirect.file = tokens[++m_position].text;

				cmd.redirects.push_back(redirect);
			}
		}

		else if (token.type == TokenType::REDIRECT_FD)
		{

		    	Redirection redirect;

    			redirect.type = RedirectType::FD_DUP;
    			redirect.sourceFD = 1;
    			redirect.targetFD = 2;

    			cmd.redirects.push_back(redirect);
}

		else if (token.type== TokenType::APPEND)
		{
			m_position++;
			if (m_position < tokens.size())
			{
				Redirection redirect;

				redirect.type = RedirectType::APPEND;
				redirect.file = tokens[m_position].text;

				cmd.redirects.push_back(redirect);
			}
		}
		m_position++;
	}

	return cmd;
}

Pipeline Parser::ParsePipeline(const std::vector<Token>& tokens)
{
    Pipeline pipeline;
    Command current;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        const auto& token = tokens[i];

        if (token.type == TokenType::WORD)
        {
            if (current.name.empty())
            {
                current.name = token.text;
            }
            else
            {
                current.args.push_back(token.text);
            }
        }

        else if (token.type == TokenType::REDIRECT_IN)
        {
            if (i + 1 < tokens.size())
            {
                Redirection redirect;

                redirect.type = RedirectType::INPUT;
                redirect.file = tokens[++i].text;

                current.redirects.push_back(redirect);
            }
        }

        else if (token.type == TokenType::REDIRECT_OUT)
        {
            if (i + 1 < tokens.size())
            {
                Redirection redirect;

                redirect.type = RedirectType::OUTPUT;
                redirect.file = tokens[++i].text;

                current.redirects.push_back(redirect);
            }
        }

	else if (token.type == TokenType::REDIRECT_FD)
	{
    		Redirection redirect;

    		redirect.type = RedirectType::FD_DUP;
    		redirect.sourceFD = 1;
    		redirect.targetFD = 2;

    		current.redirects.push_back(redirect);
	}

	else if (token.type == TokenType::REDIRECT_ERR_APPEND)
	{
		if (i + 1 < tokens.size())
		{

			Redirection redirect;

			redirect.type = RedirectType::ERROR_APPEND;
			redirect.file = tokens[++m_position].text;

			current.redirects.push_back(redirect);
		}
	}

	else if (token.type ==TokenType::REDIRECT_ERR)
	{
		if (i + 1 < tokens.size())
		{
			Redirection redirect;

			redirect.type = RedirectType::ERROR;
			redirect.file = tokens[++i].text;

			current.redirects.push_back(redirect);
		}
	}

        else if (token.type == TokenType::APPEND)
        {
            if (i + 1 < tokens.size())
            {
                Redirection redirect;

                redirect.type = RedirectType::APPEND;
                redirect.file = tokens[++i].text;

                current.redirects.push_back(redirect);
            }
        }

        else if (token.type == TokenType::PIPE)
        {
            if (!current.name.empty())
            {
                pipeline.commands.push_back(current);
                current = Command();
            }
        }
    }

    if (!current.name.empty())
    {
        pipeline.commands.push_back(current);
    }

    return pipeline;
}
