/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:12 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/09 14:25:07 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	in_quotes(char c, int quotes)
{
	int	current;

	current = quotes;
	if (c == '\'')
	{
		if (current == 0)
			quotes = '\'';
		else if (current == '\'')
			quotes = 0;
	}
	if (c == '"')
	{
		if (current == 0)
			quotes = '"';
		else if (current == '"')
			quotes = 0;
	}
	return (quotes);
}

int	check_quotes(char *line)
{
	int	i;
	int	quotes;

	i = -1;
	quotes = 0;
	while (line[++i])
		quotes = in_quotes(line[i], quotes);
	if (quotes != 0)
		ft_dprintf(1, "%sminishell: error: quotes never closed", RED);
	return (quotes == 0);
}

//*
// 	Return the end of the first arg of given str
// 	It's like a wrapper for get_arg_end() that jump directly to the closing quotes
// 	It return get_arg_end() with the index of the closing quote
// 		(if the arg starts with quotes, index_of need to find the first quote,
// 		if it doesn't start with quotes but contains quotes,
// 			index_of need to find the second quote, because the first is the opening quote
// 	Return -2 if there is not any quotes
// */
int	find_quotes_end(char *str, int len_arg)
{
	int		end;
	char	c;

	end = -21;
	if (str[0] == '\'' || str[0] == '"')
		end = arg_end(str, index_of(&str[1], &str[0], 1) + 2);

	else if (len_arg > -1 && len_arg > index_of(str, "'", 1))
		end = arg_end(str, index_of(str + 1, "'", 2) + 2);

	else if (len_arg > -1 && len_arg > index_of(str, "\"", 1))
		end = arg_end(str, index_of(str + 1, "\"", 2) + 2);

	return (end);
}
