/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:03:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/06 16:04:12 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void	free_cmds(t_cmd **cmds)
{
	t_cmd	*tmp;
	t_cmd	*lst;

	lst = *cmds;
	while (lst)
	{
		tmp = lst->next;
		free(lst->command);
		free(lst->outfiles);
		free(lst->infiles);
		free_arr(lst->args);
		free(lst);
		lst = tmp;
	}
	*cmds = NULL;
}

void	free_all(t_list	**env, t_cmd *cmds, char *line)
{
	rl_clear_history();
	ft_lstclear(env);
	free_cmds(&cmds);
	free(line)
}

void	ft_quit(t_list	**env, t_cmd *cmds, int status)
{
	rl_clear_history();
	ft_lstclear(env);
	free_cmds(&cmds);
	ft_printf("exit\n");
	exit(status);
}