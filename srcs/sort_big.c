#include "sort.h"

int     get_min(t_list **a)
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
    return (min);
}

int     get_pos_max(t_list **a)
{
    int		max;
	int		pos_max;
	int		pos;
    t_list	*tmp;
    
    max = ft_atoi((char *)(*a)->content);
	pos_max = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) > max)
		{
			max = ft_atoi((char *)tmp->content);
			pos_max = pos;
        }
		pos++;
		tmp = tmp->next;
	}
    return (pos_max);
}

int     get_max(t_list **a)
{
    int		max;
	int		pos_max;
	int		pos;
    t_list	*tmp;
    
    max = ft_atoi((char *)(*a)->content);
	pos_max = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (ft_atoi((char *)tmp->content) > max)
		{
			max = ft_atoi((char *)tmp->content);
			pos_max = pos;
        }
		pos++;
		tmp = tmp->next;
	}
    return (max);
}

int     get_pivot(t_list **a, int step, int number_steps)
{
    int     min;
    int     max;

    min = get_min(a);
    max = get_max(a);

    //printf("max : %d\n", max);
    //printf("min : %d\n", min);
    return ((max - min) * step / number_steps + min);
}

int     get_movment(t_list **a, t_list **b)
{
    int len;
    int pos_max;
    int pos_min;
    int ret_pos;
    int nbr_movment1;
    int nbr_movment2;
    int ret1;
    int ret2;

    pos_max = get_pos_max(b);
    pos_min =get_pos_min(b);
    len =ft_lstsize(*b);
    ret_pos = pos_max;
    nbr_movment1 = len - pos_max;
    nbr_movment2 = pos_max;
    ret1 = 1;
    ret2 = 2;
    if (len - pos_min < nbr_movment1)
    {
        nbr_movment1 = len - pos_min;
        ret1 = 0;
    }
    if (pos_min < nbr_movment2)
    {
        nbr_movment2 = pos_min;
        ret2 = 0;
    }
    if (nbr_movment1 < nbr_movment2)
    {
        while (nbr_movment1--)
        {
            rrb(a, b);
            write(1, "rrb\n", 4);
        }
        pa(a, b);
        write(1, "pa\n", 3);
        return (ret1);
    }
    else
    {
        while (nbr_movment2--)
        {
            rb(a, b);
            write(1, "rb\n", 3);
        }
        pa(a, b);
        write(1, "pa\n", 3);
        return (ret2);
    }
}

void    sort_sample(t_list **a, t_list **b, int pivot)
{
    int     len;
    int     index_to_push;
    int     nbr_movment;
    t_list  *tmp;

    len = ft_lstsize(*a);
    while (len--)
    {
        tmp = *a;
        if (ft_atoi((char *)tmp->content) < pivot)
        {
            pb(a, b);
            write(1, "pb\n", 3);
        }
        else
        {
            ra(a, b);
            write(1, "ra\n", 3);
        }
    }

    len = ft_lstsize(*b);
    while (len--)
    {
        tmp = *b;
        if (get_movment(a, b) == 0)
        {
            ra(a, b);
            write(1, "ra\n", 3);
        }
    }
}

void	sort_infinite_elem(t_list **a, t_list **b)
{
    int     len;
    int     pivot;
    int     number_steps;
    int     step;

    len = ft_lstsize(*a);
    step = 0;
    number_steps = len / 50;
    if (number_steps * 50 != len)
        number_steps++;
    while (step++ < number_steps)
    {
        pivot = get_pivot(a, step, number_steps);
        //printf("pivot : %d\n", pivot);
        sort_sample(a, b, pivot);                                                                                                                                                                                                         
    }

}