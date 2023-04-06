/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:00:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/06 16:21:45 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_line_space(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isspace(line[i]))
			return (0);
	return (1);
}

t_cmd	*parse_line(char *line)
{
	t_list	*list;
	t_cmd	*tab_cmd;

	if (ft_line_space(line) || !check_quotes(line) || !split_line(&list, line))
		return (NULL);
	if (check_meta_char(list) || !cmd_tab_creation(&tab_cmd, list))
	{
		ft_lstclear(&list);
		return (NULL);
	}
	ft_lstclear(&list);
	return (tab_cmd);
}
