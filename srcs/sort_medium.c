/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		place_min_top(t_list **a, t_list **b, int pos_min)
{
	if (pos_min <= ft_lstsize(*a) / 2)
	{
		while (pos_min--)
		{
			ra(a, b);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (pos_min < ft_lstsize(*a))
		{
			rra(a, b);
			write(1, "rra\n", 4);
			pos_min++;
		}
	}
}

void		sort_fifty_elem(t_list **a, t_list **b)
{
	int		pos_min;
	int		size;

	while (ft_lstsize(*a) > 3)
	{
		pos_min = get_pos_min(a);
		place_min_top(a, b, pos_min);
		pb(a, b);
		write(1, "pb\n", 3);
	}
	sort_three_elem(a, b);
	size = ft_lstsize(*b);
	while (size)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		size--;
	}
}
