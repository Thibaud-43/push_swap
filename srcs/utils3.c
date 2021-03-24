/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		printnumber2(char *str, t_list *a, t_list *b, t_flags *flags)
{
	while (a || b)
	{
		if (a)
		{
			if (flags->color)
				printf("\33[1;35m");
			printf(" %11s", (char *)a->content);
			printf("  \033[0m");
			a = a->next;
		}
		else
		{
			printf(" %11s  ", "");
		}
		if (b)
		{
			if (flags->color)
				printf("\33[1;33m");
			printf(" %-11s", (char *)b->content);
			printf("\033[0m");
			b = b->next;
		}
		printf("\n");
	}
}

int			check_order2(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (*b)
		return (0);
	while ((*tmp).next)
	{
		if (ft_atoi((*tmp).content) > ft_atoi((*tmp).next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
