#include "sort.h"

void	ft_three_elem(t_list **a, t_list **b)
{
	//ft_putstr_fd((char *)(*a)->next->next->content, 1);
	//printf("%d\n", ft_strcmp((char *)(*a)->content, (char *)(*a)->next->next->content));

	// 2 1 3
	if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) < ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
	}
	// 3 2 1
	else if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->next->content) > ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
		rra(a, b);
		write(1, "rra\n", 4);
	}
	//3 1 2
	else if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) < ft_atoi((char*)(*a)->next->next->content))
	{
		ra(a, b);
		write(1, "ra\n", 3);
	}
	// 1 3 2
	else if (ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->content) && ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) > ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
		ra(a, b);
		write(1, "ra\n", 3);
	}
	// 2 3 1
	else
	{
		rra(a, b);
		write(1, "rra\n", 4);
	}
}

void	ft_fifty_elem(t_list **a, t_list **b)
{
	int		min;
	int		pos_min;
	int		pos;
	int		size;
	t_list	*tmp;

	while (ft_lstsize(*a) > 3)
	{
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
		//printf("min : %d \n", min);
		//printf("pos : %d \n", pos_min);
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
		pb(a, b);
		write(1, "pb\n", 3);
	}
	ft_three_elem(a, b);
	size = ft_lstsize(*b);
	while(size)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		size--;
	}
}

void	ft_sort_list(t_list **a, t_list **b)
{
	int		size;

	size  = ft_lstsize(*a);
	if (size <= 3)
	{
		ft_three_elem(a, b);
	}
	else if (size <= 50)
	{
		ft_fifty_elem(a, b);
	}
}

int main(int argc, char const *argv[])
{
	char	**commands;
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	get_list_from_argv(&a, (char **)argv + 1);
	ft_sort_list(&a, &b);
	
	
	ft_exit(a, b);	
	return 0;
}