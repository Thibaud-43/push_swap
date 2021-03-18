#include "sort.h"


void    push_min_or_max_in_a(t_list **a, t_list **b, t_bigsort *bs)
{
    int count;

    bs->len_b = ft_lstsize(*b);
    bs->top  = 0;
    while (bs->len_b && (*b))
    {
        bs->len_b = ft_lstsize(*b);
        bs->pos_max = get_pos_max(b);
        bs->pos_min = get_pos_min(b);
        if (bs->pos_max <= bs->pos_min)
        {
            bs->nbr_movment = bs->pos_max;
            bs->min_or_max = 1;
            bs->movment_type = 0;
        }
        else
        {
            bs->nbr_movment = bs->pos_min;
            bs->min_or_max = 0;
            bs->movment_type = 0;
        }
        if (bs->nbr_movment > bs->len_b - bs->pos_max | bs->nbr_movment > bs->len_b - bs->pos_min)
        {
            if (bs->len_b - bs->pos_max <= bs->len_b - bs->pos_min)
            {
                bs->nbr_movment = bs->len_b - bs->pos_max;
                bs->min_or_max = 1;
                bs->movment_type = 1;
            }
            else
            {
                bs->nbr_movment = bs->len_b - bs->pos_min;
                bs->min_or_max = 0;
                bs->movment_type = 1;
            }
        }
        if (bs->movment_type == 1)
        {
            while (bs->nbr_movment--)
            {
                rrb(a, b);
                write(1, "rrb\n", 4);
            }
        }
        else
        {
            while (bs->nbr_movment--)
            {
                rb(a, b);
                write(1, "rb\n", 3);
            }
        }
        if (bs->min_or_max)
        {
            pa(a, b);
            write(1, "pa\n", 3);
            bs->top++;
        }
        else
        {
            pa(a, b);
            write(1, "pa\n", 3);
            ra(a, b);
            write(1, "ra\n", 3);
        }
    }
    while (bs->top--)
    {
        ra(a, b);
        write(1, "ra\n", 3);
    }
    
}

void    push_under_pivot_in_b(t_list **a, t_list **b, t_bigsort *bs)
{
    int     count;
    int     count2;

    count = bs->cursor_max;
    count2 = 0;
    while (count--)
    {
        if (ft_atoi((char *)(*a)->content) <= bs->pivot)
        {
            pb(a, b);
            write(1, "pb\n", 3);
        }
        else
        {
            ra(a, b);
            write(1, "ra\n", 3);
            count2++;
        }
    }
    while (count2--)
    {
        rra(a, b);
        write(1, "rra\n", 4);
    }
    bs->cursor_max -= ft_lstsize(*b);
}

void	sort_infinite_elem(t_list **a, t_list **b)
{
    t_bigsort   bs;

    bs.len_a = ft_lstsize(*a);
    bs.step = 0;
    bs.number_steps = bs.len_a / 50;
    bs.cursor_min = 0;
    bs.cursor_max = bs.len_a;
    if (bs.number_steps * 50 != bs.len_a)
        bs.number_steps++;
    while (bs.step++ < bs.number_steps)
    {
        get_pivot(a, &bs);
        push_under_pivot_in_b(a, b, &bs);
        push_min_or_max_in_a(a, b, &bs);                                                                                                                                                                               
    }
}