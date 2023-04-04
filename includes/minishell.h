/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:32 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/19 13:35:44 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define SIZE 1024

/*-------------------------HEAD-------------------------*/
# include "../libft/libft.h"
# include "struct.h"
# include <string.h>
# include <errno.h>

/*-------------------------FCTN-------------------------*/

/*---------------BUILTIN---------------*/
t_pick_builtin	main_builtin(char *command);
int				cd_main(int ac, char **av, char **env);
int				echo_main(int ac, char **av, char **env);
int				env_main(int ac, char **av, char **env);
int				exit_main(int ac, char **av, char **env);
int				export_main(int ac, char **av, char **env);
int				pwd_main(int ac, char **av, char** env);
int				unset_main(int ac, char **av, char **env);

#endif