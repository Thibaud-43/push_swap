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

int				get_min(t_list **a, int count)
{
	int		min;
	int		pos_min;
	int		pos;
	t_list	*tmp;

	min = ft_atoi((char *)(*a)->content);
	pos_min = 0;
	pos = 0;
	tmp = *a;
	while (tmp && count--)
	{
		if (ft_atoi((char *)tmp->content) < min)
		{
			min = ft_atoi((char *)tmp->content);
			pos_min = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min);
}

int				get_max(t_list **a, int count)
{
	int		max;
	int		pos_max;
	int		pos;
	t_list	*tmp;

	max = ft_atoi((char *)(*a)->content);
	pos_max = 0;
	pos = 0;
	tmp = *a;
	while (tmp && count--)
	{
		if (ft_atoi((char *)tmp->content) > max)
		{
			max = ft_atoi((char *)tmp->content);
			pos_max = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max);
}

int				get_pos_max(t_list **a)
{
	int		max;
	int		pos_max;
	int		pos;
	t_list	*tmp;

	max = ft_atoi((char *)(*a)->content);
	pos_max = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) > max)
		{
			max = ft_atoi((char *)tmp->content);
			pos_max = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (pos_max);
}

int				get_pos_min(t_list **a)
{
	int		min;
	int		pos_min;
	int		pos;
	t_list	*tmp;

	min = ft_atoi((char *)(*a)->content);
	pos_min = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) < min)
		{
			min = ft_atoi((char *)tmp->content);
			pos_min = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (pos_min);
}

void			get_pivot(t_list **a, t_bigsort *bs)
{
	int		min;
	int		max;

	min = get_min(a, bs->len_a + 1);
	max = get_max(a, bs->len_a + 1);
	bs->pivot = (max - min) * bs->step / bs->number_steps + min;
}
