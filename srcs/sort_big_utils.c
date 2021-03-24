/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		push_min_or_max_in_a5(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	if (bs->min_or_max)
	{
		pa(a, b);
		write(flags->file_redir_dst, "pa\n", 3);
		bs->top++;
	}
	else
	{
		pa(a, b);
		write(flags->file_redir_dst, "pa\n", 3);
		ra(a, b);
		write(flags->file_redir_dst, "ra\n", 3);
	}
}

void		push_min_or_max_in_a4(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	if (bs->movment_type == 1)
	{
		while (bs->nbr_movment--)
		{
			rrb(a, b);
			write(flags->file_redir_dst, "rrb\n", 4);
		}
	}
	else
	{
		while (bs->nbr_movment--)
		{
			rb(a, b);
			write(flags->file_redir_dst, "rb\n", 3);
		}
	}
}

void		push_min_or_max_in_a3(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	bs->len_b = ft_lstsize(*b);
	bs->pos_max = get_pos_max(b);
	bs->pos_min = get_pos_min(b);
	if (bs->pos_max <= bs->pos_min)
	{
		bs->nbr_movment = bs->pos_max;
		bs->min_or_max = 1;
		bs->movment_type = 0;
	}
	else
	{
		bs->nbr_movment = bs->pos_min;
		bs->min_or_max = 0;
		bs->movment_type = 0;
	}
}

void		push_min_or_max_in_a2(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	if (bs->nbr_movment > bs->len_b - bs->pos_max |
	bs->nbr_movment > bs->len_b - bs->pos_min)
	{
		if (bs->len_b - bs->pos_max <= bs->len_b - bs->pos_min)
		{
			bs->nbr_movment = bs->len_b - bs->pos_max;
			bs->min_or_max = 1;
			bs->movment_type = 1;
		}
		else
		{
			bs->nbr_movment = bs->len_b - bs->pos_min;
			bs->min_or_max = 0;
			bs->movment_type = 1;
		}
	}
}

void		push_min_or_max_in_a(t_list **a, t_list **b, t_bigsort *bs, t_flags *flags)
{
	int count;

	bs->len_b = ft_lstsize(*b);
	bs->top = 0;
	while (bs->len_b && (*b))
	{
		push_min_or_max_in_a3(a, b, bs, flags);
		push_min_or_max_in_a2(a, b, bs, flags);
		push_min_or_max_in_a4(a, b, bs, flags);
		push_min_or_max_in_a5(a, b, bs, flags);
	}
	while (bs->top--)
	{
		ra(a, b);
		write(flags->file_redir_dst, "ra\n", 3);
	}
}
