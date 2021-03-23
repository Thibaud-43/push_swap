/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		ft_init_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (size)
	{
		tab[i] = 0;
		i++;
		size--;
	}
}

int			ft_is_in_tab(int nb, int *tab, int size)
{
	int i;

	i = 0;
	while (size)
	{
		if (nb == tab[i] && nb != 0)
			return (1);
		i++;
		size--;
	}
	return (0);
}

int			check_double(t_list **a)
{
	int		size;
	int		*tab;
	int		nb;
	int		i;
	t_list	*tmp;

	tmp = *a;
	size = ft_lstsize(*a);
	i = 0;
	if (!(tab = malloc(sizeof(int) * size)))
		return (1);
	ft_init_tab(tab, size);
	while (tmp)
	{
		nb = ft_atoi((char *)tmp->content);
		if (ft_is_in_tab(nb, tab, size))
			return (1);
		else
			tab[i++] = ft_atoi((char *)tmp->content);
		tmp = tmp->next;
	}
	free(tab);
	return (0);
}

void		printnumber(char *str, t_list *a, t_list *b)
{
	printf("\e[H\e[2J\33[1;34m\n\n     -----------------\n    | COM"
	"MAND : %5s | \n     -----------------\n\n"
	"\033[0m%11c  |  %-11c\n         ----------\n", str, 'A', 'B');
	while (a || b)
	{
		if (a)
		{
			printf("\33[1;35m %11s  \033[0m", (char *)a->content);
			a = a->next;
		}
		else
		{
			printf(" %11s  ", "");
		}
		if (b)
		{
			printf("\33[1;33m %-11s\033[0m", (char *)b->content);
			b = b->next;
		}
		printf("\n");
	}
}
