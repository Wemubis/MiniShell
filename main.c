/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:36 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/05 18:29:58 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_tok	*cmds;
	t_list	*top_envp;

	(void)ac;
	(void)av;
	top_envp = NULL;
	dup_env(env, &top_envp);
	while (1)
	{
		line = readline("mini$> ");
		if (!line)
			ft_quit(&top_envp, parse_cmd, 0);
		cmds = parse_line(line);
		if (!cmds)
		{
			free_arr(cmds);
			continue ;
		}
		exec_cmds(&top_envp, cmds);
		free_arr(cmds);
	}
	return (free_all(&top_envp, cmds, line), 0);
}
