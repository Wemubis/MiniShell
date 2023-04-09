/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:12 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/09 23:38:04 by mle-boud         ###   ########.fr       */
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


