#include "sort.h"

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