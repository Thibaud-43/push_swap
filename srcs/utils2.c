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

int			ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}

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

void		printnumber(char *str, t_list *a, t_list *b, t_flags *flags)
{
	if (flags->display == 0)
		return ;
	printf("\e[H\e[2J");
	if (flags->color)
		printf("\33[1;34m\n\n");
	printf("     -----------------\n    | COM"
	"MAND : %5s | \n     -----------------\n\n", str);
	printf("\033[0m");
	printf("%11c  |  %-11c\n         ----------\n", 'A', 'B');
	printnumber2(str, a, b, flags);
	usleep(flags->time);
}
