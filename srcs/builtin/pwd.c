/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:50:44 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/16 17:56:55 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_main(int ac, char **av, char** env)
{
	char	buffer[SIZE];

	(void)ac;
	(void)av;
	(void)env;
	ft_printf("%s\n", getcwd(buffer, SIZE - 1));
	return(0);
}
