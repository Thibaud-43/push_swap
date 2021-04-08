/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_command1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	apply_sa(t_stacks *s, t_flags *flags)
{
	sa(&(s->a), &(s->b));
	printnumber("sa", (s->a), (s->b), flags);
}

void	apply_rra(t_stacks *s, t_flags *flags)
{
	rra(&(s->a), &(s->b));
	printnumber("rra", s->a, s->b, flags);
}

void	apply_rrb(t_stacks *s, t_flags *flags)
{
	rrb(&(s->a), &(s->b));
	printnumber("rrb", s->a, s->b, flags);
}

void	apply_rrr(t_stacks *s, t_flags *flags)
{
	rrr(&(s->a), &(s->b));
	printnumber("rrr", s->a, s->b, flags);
}

void	apply_rr(t_stacks *s, t_flags *flags)
{
	rr(&(s->a), &(s->b));
	printnumber("rr", s->a, s->b, flags);
}
