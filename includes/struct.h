/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/06 13:49:56 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*---------------BUILTIN---------------*/
typedef int	(*t_pick_builtin)(int ac, char **av, char **env);

/*---------------PARSING---------------*/
typedef enum e_type_char
{
	CMD,
	PIPE,
	AND,
	OR,
	IN,
	OUT,
} t_type_char;

typedef struct s_cmd
{
	char		*name;
	t_type_char	type;
} t_cmd;

#endif