/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_three_elem2(t_list **a, t_list **b, t_flags *flags)
{
	if (ft_atoi((char*)(*a)->content) <
	ft_atoi((char*)(*a)->next->content)
	&& ft_atoi((char*)(*a)->content) <
	(ft_atoi((char*)(*a)->next->next->content))
	&& ft_atoi((char*)(*a)->next->content) >
	(ft_atoi((char*)(*a)->next->next->content)))
	{
		sa(a, b);
		write(flags->file_redir_dst, "sa\n", 3);
		ra(a, b);
		write(flags->file_redir_dst, "ra\n", 3);
		return ;
	}
	if (!(ft_atoi((char*)(*a)->content) <
	ft_atoi((char*)(*a)->next->content)
	&& ft_atoi((char*)(*a)->content) <
	(ft_atoi((char*)(*a)->next->next->content))
	&& ft_atoi((char*)(*a)->next->content) <
	(ft_atoi((char*)(*a)->next->next->content))))
	{
		rra(a, b);
		write(flags->file_redir_dst, "rra\n", 4);
		return ;
	}
}

void	sort_three_elem3(t_list **a, t_list **b, t_flags *flags)
{
	if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)
	&& ft_atoi((char*)(*a)->content) >
	(ft_atoi((char*)(*a)->next->next->content))
	&& ft_atoi((char*)(*a)->next->content) <
	(ft_atoi((char*)(*a)->next->next->content)))
	{
		ra(a, b);
		write(flags->file_redir_dst, "ra\n", 3);
		return ;
	}
	else
		sort_three_elem2(a, b, flags);
}

void	sort_three_elem(t_list **a, t_list **b, t_flags *flags)
{
	if (ft_atoi((char*)(*a)->content) >
	ft_atoi((char*)(*a)->next->content)
	&& ft_atoi((char*)(*a)->content) <
	(ft_atoi((char*)(*a)->next->next->content))
	&& ft_atoi((char*)(*a)->next->content) <
	(ft_atoi((char*)(*a)->next->next->content)))
	{
		sa(a, b);
		write(flags->file_redir_dst, "sa\n", 3);
		return ;
	}
	if (ft_atoi((char*)(*a)->content) >
	ft_atoi((char*)(*a)->next->content)
	&& ft_atoi((char*)(*a)->next->content) >
	(ft_atoi((char*)(*a)->next->next->content))
	&& ft_atoi((char*)(*a)->content) >
	(ft_atoi((char*)(*a)->next->next->content)))
	{
		sa(a, b);
		write(flags->file_redir_dst, "sa\n", 3);
		rra(a, b);
		write(flags->file_redir_dst, "rra\n", 4);
		return ;
	}
	sort_three_elem3(a, b, flags);
}
