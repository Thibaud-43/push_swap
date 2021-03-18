#include "sort.h"

void	sort_three_elem(t_list **a, t_list **b)
{
	if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) < ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
	}
	else if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->next->content) > ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
		rra(a, b);
		write(1, "rra\n", 4);
	}
	else if (ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->content)  && ft_atoi((char*)(*a)->content) > ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) < ft_atoi((char*)(*a)->next->next->content))
	{
		ra(a, b);
		write(1, "ra\n", 3);
	}
	else if (ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->content) && ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) > ft_atoi((char*)(*a)->next->next->content))
	{
		sa(a, b);
		write(1, "sa\n", 3);
		ra(a, b);
		write(1, "ra\n", 3);
	}
	else if (ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->content) && ft_atoi((char*)(*a)->content) < ft_atoi((char*)(*a)->next->next->content) && ft_atoi((char*)(*a)->next->content) < ft_atoi((char*)(*a)->next->next->content))
	{
		
	}
	else
	{
		rra(a, b);
		write(1, "rra\n", 4);
	}
}
