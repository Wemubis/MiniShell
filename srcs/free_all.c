/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:03:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/05 13:44:05 by mle-boud         ###   ########.fr       */
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

void	free_all(char **envp, char **parse_cmd, char *line)
{
	rl_clear_history();
	free_arr(envp);
	free_arr(parse_cmd);
	free(line)
}

void	ft_quit(char **envp, char **parse_cmd, int status)
{
	rl_clear_history();
	free_arr(envp);
	free_arr(parse_cmd);
	ft_printf("exit\n");
	exit(status);
}