/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		push_under_pivot_in_b(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	int		count;
	int		count2;

	count = bs->cursor_max;
	count2 = 0;
	while (count--)
	{
		if (ft_atoi((char *)(*a)->content) <= bs->pivot)
		{
			pb(a, b);
			write(flags->file_redir_dst, "pb\n", 3);
		}
		else
		{
			ra(a, b);
			write(flags->file_redir_dst, "ra\n", 3);
			count2++;
		}
	}
	while (count2--)
	{
		rra(a, b);
		write(flags->file_redir_dst, "rra\n", 4);
	}
	bs->cursor_max -= ft_lstsize(*b);
}

void		sort_infinite_elem(t_list **a, t_list **b, t_flags *flags)
{
	t_bigsort	bs;

	bs.len_a = ft_lstsize(*a);
	bs.step = 0;
	bs.number_steps = bs.len_a / 50;
	bs.cursor_min = 0;
	bs.cursor_max = bs.len_a;
	if (bs.number_steps * 50 != bs.len_a)
		bs.number_steps++;
	while (bs.step++ < bs.number_steps)
	{
		get_pivot(a, &bs);
		push_under_pivot_in_b(a, b, &bs, flags);
		push_min_or_max_in_a(a, b, &bs, flags);
	}
}
