/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:50:35 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/17 00:23:37 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_main(int ac, char **av, char **env)
{
	int	i;

	i = -1;
	(void)ac;
	(void)av;
	if (env)
		while (env[++i])
			ft_printf("%s\n", env[i]);
	return(0);
}
