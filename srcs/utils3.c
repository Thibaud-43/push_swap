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

void			printchar(char *str, int align, int nb)
{
	int count;

	count = nb - ft_strlen(str);
	ft_putstr_fd(" ", 1);
	if (align)
		ft_putstr_fd(str, 1);
	while (count--)
		ft_putstr_fd(" ", 1);
	if (!align)
		ft_putstr_fd(str, 1);
}

static	void	print_eleven_char2(void)
{
	int count;

	count = 14;
	while (count--)
		ft_putstr_fd(" ", 1);
}

void			printnumber2(char *str, t_list *a, t_list *b, t_flags *flags)
{
	while (a || b)
	{
		if (a)
		{
			if (flags->color)
				ft_putstr_fd("\33[1;35m", 1);
			printchar((char *)a->content, 0, 11);
			ft_putstr_fd("  \033[0m", 1);
			a = a->next;
		}
		else
		{
			print_eleven_char2();
		}
		if (b)
		{
			if (flags->color)
				ft_putstr_fd("\33[1;33m", 1);
			printchar((char *)b->content, 1, 11);
			ft_putstr_fd("\033[0m", 1);
			b = b->next;
		}
		ft_putstr_fd("\n", 1);
	}
}

int				check_order2(t_list **a, t_list **b)
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
