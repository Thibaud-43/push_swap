/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void			check_order(t_list **a, t_list **b, t_flags *flags)
{
	t_list	*tmp;

	tmp = *a;
	if (*b)
	{
		if (flags->color)
			ft_putstr_fd("\033[0;31m", 1);
		ft_putstr_fd("KO\n\033[0m", 1);
		return ;
	}
	while ((*tmp).next)
	{
		if (ft_atoi((*tmp).content) > ft_atoi((*tmp).next->content))
		{
			if (flags->color)
				ft_putstr_fd("\033[0;31m", 1);
			ft_putstr_fd("KO\n", 1);
			ft_putstr_fd("\033[0m", 1);
			return ;
		}
		tmp = tmp->next;
	}
	if (flags->color)
		ft_putstr_fd("\033[1;32m", 1);
	ft_putstr_fd("OK\n\033[0m", 1);
}

static void		apply_commands3(t_stacks *s, char **commands,
int i, t_flags *flags)
{
	if (!ft_strcmp(commands[i], "sb"))
	{
		sb(&(s->a), &(s->b));
		printnumber("sb", (s->a), (s->b), flags);
	}
	else if (!ft_strcmp(commands[i], "pa"))
	{
		pa(&(s->a), &(s->b));
		printnumber("pa", (s->a), (s->b), flags);
	}
	else if (!ft_strcmp(commands[i], "pb"))
	{
		pb(&(s->a), &(s->b));
		printnumber("pb", (s->a), (s->b), flags);
	}
	else if (!ft_strcmp(commands[i], "ra"))
	{
		ra(&(s->a), &(s->b));
		printnumber("ra", (s->a), (s->b), flags);
	}
	else if (!ft_strcmp(commands[i], "rb"))
	{
		rb(&(s->a), &(s->b));
		printnumber("rb", (s->a), (s->b), flags);
	}
}

static int		apply_commands2(t_stacks *s, char **commands,
int i, t_flags *flags)
{
	if (!ft_strcmp(commands[i], "rra"))
	{
		rra(&(s->a), &(s->b));
		printnumber("rra", s->a, s->b, flags);
	}
	else if (!ft_strcmp(commands[i], "rrb"))
	{
		rrb(&(s->a), &(s->b));
		printnumber("rrb", s->a, s->b, flags);
	}
	else if (!ft_strcmp(commands[i], "rrr"))
	{
		rrr(&(s->a), &(s->b));
		printnumber("rrr", s->a, s->b, flags);
	}
	else if (!ft_strcmp(commands[i], "rr"))
	{
		rr(&(s->a), &(s->b));
		printnumber("rr", s->a, s->b, flags);
	}
	return (0);
}

static int		apply_commands(t_stacks *s, char **commands, t_flags *flags)
{
	int i;
	int	ret;

	i = 0;
	ret = 0;
	while (commands[i])
	{
		if (!ft_strcmp(commands[i], "sa"))
		{
			sa(&(s->a), &(s->b));
			printnumber("sa", (s->a), (s->b), flags);
		}
		apply_commands3(s, commands, i, flags);
		ret = apply_commands2(s, commands, i, flags);
		i++;
	}
	return (ret);
}

int				main(int argc, char const *argv[])
{
	char		**commands;
	t_flags		flags;
	int			i;
	t_stacks	s;

	s.a = NULL;
	s.b = NULL;
	i = check_flags((char **)argv + 1, &flags);
	if (ft_check_digits((char **)argv + i) || argc < 2)
		return (1);
	commands = get_commands_tab(&flags);
	get_list_from_argv(&s.a, (char **)argv + i);
	if (check_double(&s.a))
	{
		ft_putstr_fd("Error\n", 1);
		ft_exit(s.a, s.b, commands, &flags);
	}
	if (apply_commands(&s, commands, &flags))
		ft_exit(s.a, s.b, commands, &flags);
	check_order(&s.a, &s.b, &flags);
	ft_exit(s.a, s.b, commands, &flags);
	return (0);
}
