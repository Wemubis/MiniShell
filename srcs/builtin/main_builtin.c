/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_a_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:12:00 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/19 13:26:20 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pick_builtin	main_builtin(char *command)
{
	if (!ft_strcmp(command, "echo"))
		return (main_echo);
	if (!ft_strcmp(command, "cd"))
		return (main_cd);
	if (!ft_strcmp(command, "pwd"))
		return (main_pwd);
	if (!ft_strcmp(command, "export"))
		return (main_export);
	if (!ft_strcmp(command, "unset"))
		return (main_unset);
	if (!ft_strcmp(command, "env"))
		return (main_env);
	if (!ft_strcmp(command, "exit"))
		return (main_exit);
	return (0);
}
