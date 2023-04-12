/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:12 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/12 12:58:56 by mle-boud         ###   ########.fr       */
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

int	find_quotes_end(char *str, int len_arg)
{
	int		end;
	char	c;

	end = -42;
	if (str[0] == '\'' || str[0] == '"')
		end = end_arg(str, index(&str[1], &str[0], 1) + 2);
	else if (len_arg > -1)
	{
		if (len_arg > index(str, "'", 1))
			end = end_arg(str, index(str + 1, "'", 2) + 2);
		else if (len_arg > index(str, "\"", 1))
			end = end_arg(str, index(str + 1, "\"", 2) + 2);
	}
	return (end);
} 