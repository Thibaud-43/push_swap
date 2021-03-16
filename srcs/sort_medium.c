#include "sort.h"

int     get_pos_min(t_list **a)
{
    int		min;
	int		pos_min;
	int		pos;
    t_list	*tmp;
    
    min = ft_atoi((char *)(*a)->content);
	pos_min = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) < min)
		{
			min = ft_atoi((char *)tmp->content);
			pos_min = pos;
        }
		pos++;
		tmp = tmp->next;
	}
    return (pos_min);
}

void    place_min_top(t_list **a, t_list **b, int pos_min)
{
    if (pos_min <= ft_lstsize(*a) / 2)
	{
		while (pos_min--)
		{
			ra(a, b);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (pos_min < ft_lstsize(*a))
		{
			rra(a, b);
			write(1, "rra\n", 4);
			pos_min++;
		}
	}
}

void	sort_fifty_elem(t_list **a, t_list **b)
{
	int		pos_min;
	int		size;

	while (ft_lstsize(*a) > 3)
	{
		pos_min = get_pos_min(a);
        place_min_top(a, b, pos_min);		
		pb(a, b);
		write(1, "pb\n", 3);
	}
	sort_three_elem(a, b);
	size = ft_lstsize(*b);
	while(size)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		size--;
	}
}