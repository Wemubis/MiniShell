/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:50:38 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/17 16:21:16 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_main(int ac, char **av, char **env)
{
	int exit_value;

	(void)env;
	if (ac < 2)
		exit_value = 0;
	else if (ac == 2)
	{
		if (!ft_isdigit(av[1]))
		{
			ft_printf("error, a digit arg is reauired");
			exit_value = 2;
		}
		else
			exit_value = ft_atoi(av[2]);
	}
	else if (ac > 2)
	{
		ft_printf("too many args");
		exit_value = 1;
	}
	free_all();
	exit(exit_value);
}
