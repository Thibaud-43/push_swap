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

void	ft_sort_list(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2 && (ft_atoi((char *)(*a)->content) >
	ft_atoi((char *)(*a)->next->content)))
	{
		sa(a, b);
		write(1, "sa\n", 3);
	}
	else if (size == 3)
		sort_three_elem(a, b);
	else if (size <= 50)
		sort_fifty_elem(a, b);
	else
		sort_infinite_elem(a, b);
}

int		main(int argc, char const *argv[])
{
	char	**commands;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ft_check_digits((char **)argv + 1) || argc < 2)
		return (1);
	get_list_from_argv(&a, (char **)argv + 1);
	if (check_double(&a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_exit(a, b, commands);
	}
	ft_sort_list(&a, &b);
	ft_exit(a, b, commands);
	return (0);
}
