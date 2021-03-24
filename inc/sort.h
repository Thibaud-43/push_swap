/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <time.h>
# include <limits.h>
# define ELEM1 ft_atoi((char*)(*a)->content)
# define ELEM2 ft_atoi((char*)(*a)->next->content)
# define ELEM3 ft_atoi((char*)(*a)->next->next->content)



typedef struct		s_stacks
{
	t_list			*a;
	t_list			*b;
}					t_stacks;

typedef	struct		s_flags
{
	int			display;
	int			color;
	int			file_redir_dst;
	int			file_redir_src;
	int			help;
	int			time;
}					t_flags;

typedef	struct		s_bigsort
{
	int				len_a;
	int				len_b;
	int				pivot;
	int				cursor_min;
	int				cursor_max;
	int				step;
	int				number_steps;
	int				pos_min;
	int				pos_max;
	int				nbr_movment;
	int				min_or_max;
	int				movment_type;
	int				top;
}					t_bigsort;

void				check_order(t_list **a, t_list **b, t_flags *flags);
void				ft_exit(t_list	*a, t_list *b, char **commands, t_flags *flags);
void				get_list_from_argv(t_list **begin, char	**tab);
char				**get_commands_tab(t_flags *flags);
void				freelist(t_list *begin);
void				sort_three_elem(t_list **a, t_list **b, t_flags *flags);
void				sort_fifty_elem(t_list **a, t_list **b, t_flags *flags);
void				sort_infinite_elem(t_list **a, t_list **b, t_flags *flags);
int					get_pos_min(t_list **a);
int					get_pos_max(t_list **a);
int					get_min(t_list **a, int count);
int					get_max(t_list **a, int count);
void				get_pivot(t_list **a, t_bigsort *bs);
int					ft_check_digits(char **argv);
int					check_double(t_list **a);
void				sa(t_list **a, t_list **b);
void				sb(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ra(t_list **a, t_list **b);
void				rb(t_list **a, t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a, t_list **b);
void				rrb(t_list **a, t_list **b);
void				rrr(t_list **a, t_list **b);
void				printnumber(char *str, t_list *a, t_list *b, t_flags *flags);
void				push_min_or_max_in_a(t_list **a, t_list **b, t_bigsort *, t_flags *flags);
int					ft_error(void);
int					check_flags(char **argv, t_flags *flags);
void				printnumber2(char *str, t_list *a, t_list *b, t_flags *flags);
int					check_order2(t_list **a, t_list **b);

#endif
