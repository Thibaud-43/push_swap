/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sa(t_list **a, t_list **b)
{
	char	*tmp;

	(void)b;
	if ((*a) && (*a)->next)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
}

void	sb(t_list **a, t_list **b)
{
	char	*tmp;

	(void)a;
	if ((*b) && (*b)->next)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = tmp;
}
