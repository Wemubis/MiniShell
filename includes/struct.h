/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/07 16:39:03 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*---------------BUILTIN---------------*/
typedef int	(*t_pick_builtin)(int ac, char **av, char **env);

/*---------------PARSING---------------*/
typedef enum e_type_arg
{
	CMD,
	PIPE,
	REDIR_IN,
	REDIR_OUT
} t_type_arg;

typedef struct s_cmd
{
	char			*content;
	t_type_arg		type;
	struct s_cmd	*next;
} t_cmd;

#endif