/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:36 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/05 15:27:54 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**envp;
	t_tok	*cmds;

	(void)ac;
	(void)av;
	envp = dup_env(env);
	if (!envp)
		return (free_arr(envp), 1);
	while (1)
	{
		line = readline("mini$> ");
		if (!line)
			ft_quit(envp, parse_cmd, 0);
		cmds = parse_line(line);
		if (!cmds)
		{
			free_arr(cmds);
			continue ;
		}
		exec_cmds(envp, cmds);
		free_arr(cmds);
	}
	return (free_all(envp, cmds, line), 0);
}
