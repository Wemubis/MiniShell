/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:18:12 by mle-boud          #+#    #+#             */
/*   Updated: 2023/04/12 12:59:07 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_separator(char c)
{
	return (c == '\'' || c == '"' || c == '<' || c == '&' || c == '|' || c == '>')
}

static int	add_lst(t_list **list, char *var)
{
	t_list	*new;

	new = ft_lstnew(var);
	if (!new)
		return (ft_lstclear(list), 0);
	return (ft_lstadd_back(list, new), 1);
}

int	end_arg(char *str, int start)
{
	int		i;
	int		end;
	int		sep;
	char	**char_sep;

	char_sep = ft_split("| << < >> > &", ' ');
	if (!char_sep)
		return (0);
	end = index_of_space(&str[start]);
	i = -1;
	while (char_sep[++i])
	{
		sep = index(&str[start], char_sep[i], 1);
		if (sep < end)
		{
			end = sep;
			break ;
		}
	}
	free_arr(char_sep);
	return (end + start);
}

static int	end_index(char *str, int len_arg)
{
	int		i;
	int		end;
	char	**char_sep;

	char_sep = ft_split("| << < >> > &", ' ');
	if (!len_arg || !char_sep)
		return (0);
	end = find_quotes_end(str, len_arg); // to re check to better understand
	if (end != -42)
		return (free_arr(char_sep), end);
	i = -1;
	while (char_sep[++i])
	{
		if (len_arg > -1 && len_arg > index(str, char_sep[i], 1))
			return (free_arr(char_sep), index(str, char_sep[i], 1));
		if (!ft_strncmp(str, char_sep[i], 1))
			return (free_arr(char_sep), ft_strlen(char_sep[i]));
	}
	return (free_arr(char_sep), len_arg);
}

int	split_line(t_list **list, char *line)
{
	int		i;
	int		j;
	int		end;
	char	*content;

	i = -1;
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			continue ;
		j = -1;
		if (!is_separator(line[i]))
			j = end_arg(&line[i], 0);
		end = end_index(&line[i], j);
		if (!end)
			return (ft_lstclear(list), 0);
		content = ft_substr(line, i, (size_t)end);
		if (!content || !add_lst(list, content))
			return (ft_lstclear(list), free(content), 0)
		i += ft_strlen(content) - 1;
		free(content);
	}
	return (1);
}
