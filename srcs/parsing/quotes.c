/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:22:12 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/06 16:11:18 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	in_quotes(char c, int *quotes)
{
	int	current_quotes;

	current_quotes = *quotes;
	if (c == '\'')
	{
		if (current_quotes == 0)
			*quotes = '\'';
		else if (current_quotes == '\'')
			*quotes = 0;
	}
	if (c == '"')
	{
		if (current_quotes == 0)
			*quotes = '"';
		else if (current_quotes == '"')
			*quotes = 0;
	}
}

int	check_quotes(char *command)
{
	int	i;
	int	quotes;

	i = -1;
	quotes = 0;
	while (command[++i])
		in_quotes(command[i], &quotes);
	if (quotes != 0)
		ft_dprintf(1, "%sminishell: parse error: quotes never closed", RED);
	return (quotes == 0);
}