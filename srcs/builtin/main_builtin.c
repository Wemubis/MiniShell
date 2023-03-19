/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:12:00 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/19 13:35:06 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pick_builtin	main_builtin(char *command)
{
	if (!ft_strcmp(command, "cd"))
		return (cd_main);
	if (!ft_strcmp(command, "echo"))
		return (echo_main);
	if (!ft_strcmp(command, "env"))
		return (env_main);
	if (!ft_strcmp(command, "exit"))
		return (exit_main);
	if (!ft_strcmp(command, "export"))
		return (export_main);
	if (!ft_strcmp(command, "pwd"))
		return (pwd_main);
	if (!ft_strcmp(command, "unset"))
		return (unset_main);
	return (0);
}
