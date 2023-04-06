/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/06 15:53:02 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*---------------BUILTIN---------------*/
typedef int	(*t_pick_builtin)(int ac, char **av, char **env);

/*---------------PARSING---------------*/
typedef struct s_cmd
{
	char			*cmd;
	char			*infile;
	char			*outfile;
	char			**args;
	struct s_cmd	*next;
} t_cmd;

#endif