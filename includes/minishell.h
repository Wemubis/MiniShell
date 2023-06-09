/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:32 by mle-boud          #+#    #+#             */
/*   Updated: 2023/05/02 13:04:34 by mle-boud         ###   ########.fr       */
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
# include <stdio.h>

/*-------------------------FCTN-------------------------*/

/*---------------BUILTIN---------------*/
int				cd_main(int ac, char **av, char **env);
int				echo_main(int ac, char **av, char **env);
int				env_main(int ac, char **av, char **env);
int				exit_main(int ac, char **av, char **env);
int				export_main(int ac, char **av, char **env);
int				pwd_main(int ac, char **av, char** env);
int				unset_main(int ac, char **av, char **env);

/*----------------PARSING----------------*/
t_cmd			*parse_line(char *line);
int				split_line(t_list **list, char *line);
int				end_arg(char *str, int start);
int				check_quotes(char *line);
int				find_quotes_end(char *str, int len_arg);
int				index(char *str, char *to_find, int nb);
int				index_of_space(char *str);

/*---------------FREE-QUIT---------------*/
void			free_arr(char **arr);
void			free_cmds(t_cmd *cmds);
void			free_all(t_list	**env, t_cmd *cmds, char *line);
void			ft_quit(t_list	**env, t_cmd *cmds, int status);

/*---------------ENVIRONNEMENT---------------*/
void			dup_env(char **envp, t_list **env);

#endif