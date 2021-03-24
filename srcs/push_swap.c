/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ft_sort_list(t_list **a, t_list **b, t_flags *flags)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2 && (ft_atoi((char *)(*a)->content) >
	ft_atoi((char *)(*a)->next->content)))
	{
		sa(a, b);
		write(flags->file_redir_dst, "sa\n", 3);
	}
	else if (size == 3)
		sort_three_elem(a, b, flags);
	else if (size <= 50)
		sort_fifty_elem(a, b, flags);
	else
		sort_infinite_elem(a, b, flags);
}

int		main(int argc, char const *argv[])
{
	char		**commands;
	t_flags		flags;
	int			i;
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	commands = NULL;
	i = check_flags((char **)argv + 1, &flags);
	if (ft_check_digits((char **)argv + i) || argc < 2)
		return (1);
	get_list_from_argv(&a, (char **)argv + i);
	if (check_double(&a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_exit(a, b, commands, &flags);
	}
	ft_sort_list(&a, &b, &flags);
	ft_exit(a, b, commands, &flags);
	return (0);
}
