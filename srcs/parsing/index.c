/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:46:48 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/12 12:47:54 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	index(char *str, char *to_find, int nb)
{
	int	i;
	int	len;

	i = -1;
	len = 1;
	if (ft_strlen(to_find) == 2)
		len = 2;
	while (str[++i])
	{
		if (!ft_strncmp(&str[i], to_find, len))
			nb--;
		if (nb <= 0)
			return (i);
	}
	return (i);
}

int	index_of_space(char *str)
{
	int	space;
	int	tab;

	space = index(str, " ", 1);
	tab = index(str, "\t", 1);
	if (tab || str[0] == '\t')
		if (tab < space)
			space = tab;
	return (space);
}
