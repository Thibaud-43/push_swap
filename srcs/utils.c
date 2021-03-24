/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int				ft_check_digits(char **argv)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (!argv[i] || ft_strcmp(argv[i], "") == 0)
		return (1);
	while (argv[i])
	{
		k = 0;
		if ((ft_atoi((argv[i])) == -1 && ft_strcmp(argv[i], "-1") != 0)
		|| (ft_atoi((argv[i])) == -2 && ft_strcmp(argv[i], "-2") != 0))
			return ft_error();
		while (argv[i][k])
		{
			if (ft_isdigit(argv[i][k]) == 0 && argv[i][k] != '-')
				return ft_error();
			k++;
		}
		i++;
	}
	return (0);
}

void			ft_exit(t_list *a, t_list *b, char **commands, t_flags *flags)
{
	int i;
	i = 0;

	if (flags->file_redir_dst > 1)
		close(flags->file_redir_dst);
	if (flags->file_redir_src > 1)
		close(flags->file_redir_src);
	if (commands)
	{
		while (commands[i])
			free(commands[i++]);
		free(commands);
	}	
	freelist(a);
	freelist(b);
	exit(1);
}

char			**get_commands_tab(t_flags *flags)
{
	char	*line;
	char	*commands;
	char	*tmp;
	int		ret;
	char	**commands_tab;

	commands = ft_calloc(sizeof(char), 1);
	while ((ret = get_next_line(flags->file_redir_src, &line)))
	{
		tmp = commands;
		commands = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		tmp = commands;
		commands = ft_strjoin(tmp, "-");
		free(tmp);
	}
	free(line);
	commands_tab = ft_split(commands, '-');
	free(commands);
	return (commands_tab);
}

void			get_list_from_argv(t_list **begin, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_lstadd_back(begin, ft_lstnew(tab[i]));
		i++;
	}
	return ;
}

void			freelist(t_list *begin)
{
	t_list	*tmp;

	while (begin != NULL)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}
