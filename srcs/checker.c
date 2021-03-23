/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		check_order(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (*b)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while ((*tmp).next)
	{
		if (ft_atoi((*tmp).content) > ft_atoi((*tmp).next->content))
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("OK\n", 1);
}

static int	apply_commands2(t_list **a, t_list **b, char **commands, int i)
{
	if (!ft_strcmp(commands[i], "sa"))
		sa(a, b);
	else if (!ft_strcmp(commands[i], "sb"))
		sb(a, b);
	else if (!ft_strcmp(commands[i], "pa"))
		pa(a, b);
	else if (!ft_strcmp(commands[i], "ra"))
		ra(a, b);
	else if (!ft_strcmp(commands[i], "rb"))
		rb(a, b);
	else if (!ft_strcmp(commands[i], "rra"))
		rra(a, b);
	else if (!ft_strcmp(commands[i], "rrb"))
		rrb(a, b);
	else if (!ft_strcmp(commands[i], "rrr"))
		rrr(a, b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

static int	apply_commands(t_list **a, t_list **b, char **commands)
{
	int i;
	int	ret;

	i = 0;
	ret = 0;
	while (commands[i])
	{
		ret = apply_commands2(a, b, commands, i);
		i++;
	}
	return (ret);
}

int			main(int argc, char const *argv[])
{
	char		**commands;
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	if (ft_check_digits((char **)argv + 1) || argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	commands = get_commands_tab();
	get_list_from_argv(&a, (char **)argv + 1);
	if (check_double(&a))
	{
		ft_putstr_fd("Error\n", 1);
		ft_exit(a, b);
	}
	if (apply_commands(&a, &b, commands))
		ft_exit(a, b);
	check_order(&a, &b);
	ft_exit(a, b);
	return (0);
}
