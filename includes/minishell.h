/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:32 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/05 18:23:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define SIZE 1024
#define BUFF_SIZE 8192

/*-------------------------HEAD-------------------------*/
# include "../libft/libft.h"
# include "struct.h"
# include <string.h>
# include <errno.h>
# include <stdio.h>

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

/*---------------FREE-QUIT---------------*/
void	free_arr(char **arr);
void	free_all(char **envp, char **parse_cmd, char *line);
void	ft_quit(char **envp, char **parse_cmd, int status);

/*---------------ENVIRONNEMENT---------------*/
void	dup_env(char **envp, t_list **env);

#endif