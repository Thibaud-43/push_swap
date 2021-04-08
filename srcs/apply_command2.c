/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	apply_sb(t_stacks *s, t_flags *flags)
{
	sb(&(s->a), &(s->b));
	printnumber("sb", (s->a), (s->b), flags);
}

void	apply_pa(t_stacks *s, t_flags *flags)
{
	pa(&(s->a), &(s->b));
	printnumber("pa", (s->a), (s->b), flags);
}

void	apply_pb(t_stacks *s, t_flags *flags)
{
	pb(&(s->a), &(s->b));
	printnumber("pb", (s->a), (s->b), flags);
}

void	apply_ra(t_stacks *s, t_flags *flags)
{
	ra(&(s->a), &(s->b));
	printnumber("ra", (s->a), (s->b), flags);
}

void	apply_rb(t_stacks *s, t_flags *flags)
{
	rb(&(s->a), &(s->b));
	printnumber("rb", (s->a), (s->b), flags);
}
