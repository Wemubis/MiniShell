/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:52:19 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/17 17:11:46 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fail_dup_env(t_list **env)
{
	ft_lstclear(env);
	ft_dprintf(1,"Fail dup_env");
	exit(1);
}

static void	add_line(char *var, int i, t_list **env)
{
	t_list	*new;

	new = ft_lstnew(var);
	if (!new)
		fail_dup_env(env);
	if (i == 0)
		*env = new;
	else 
		ft_lstadd_back(env, new);
}

void	dup_env(char **envp, t_list **env)
{
	char	*var;
	int		i;

	i = -1;
	while (envp[++i])
	{
		var = ft_strdup(envp[i]);
		add_line(var, i, env);
		free(var);
		var = NULL;
	}
}