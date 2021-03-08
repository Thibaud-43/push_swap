#include "sort.h"

void	sa(t_list **a, t_list **b)
{
	char	*tmp;
	(void)b;

	if ((*a) && (*a)->next)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
}

void	sb(t_list **a, t_list **b)
{
	char	*tmp;
	(void)a;

	if ((*b) && (*b)->next)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}	
}

void	ss(t_list **a, t_list **b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*b))
		return;
	tmp = (*b)->next;
	(*b)->next = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!(*a))
		return;
	tmp = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = tmp;
}

void	ra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*a))
		return;

	tmp = (*a);
	tmp2 = (*a);
	(*a) = (*a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp2->next = NULL;
	tmp->next = tmp2;
	
	return;
}

void	rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*b))
		return;

	tmp = (*b);
	tmp2 = (*b);
	(*b) = (*b)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp2->next = NULL;
	tmp->next = tmp2;
	return;
}

void	rr(t_list **a, t_list **b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*a))
		return;
	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = (*a);
	(*a) = tmp2;

	return;
}

void	rrb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*b))
		return;
	tmp = (*b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = (*b);
	(*b) = tmp2;
		
	return;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, b);
	rrb(a, b);
}