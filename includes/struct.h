/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:57 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*---------------PARSING---------------*/
typedef enum e_type_arg
{
	CMD,
	ARG,
	PIPE,
	INFILE,
	OUTFILE,
	HEREDOCS,
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