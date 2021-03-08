# ifndef SORT_H
# define SORT_H

/*
*	LIBRARIES
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

/*
*	PROTOTYPES
*/

/* 
*	Swap the first 2 elements at the top of stack a. 
*	Do nothing if there is only one or no elements).
*/
void	sa(t_list **a, t_list **b);


/* 
*	Swap the first 2 elements at the top of stack b. 
*	Do nothing if there is only one or no elements).
*/
void	sb(t_list **a, t_list **b);


/* 
* 	Push a - take the first element at the top of b and put it at the top of a. 
* 	Do nothing if b is empty
*/
void	pa(t_list **a, t_list **b);


/*
*	push b - take the first element at the top of a and put it at the top of b.
*	Do nothing if a is empty
*/
void	pb(t_list **a, t_list **b);


/*
*	rotate a - shift up all elements of stack a by 1.
*	The first element becomes the last one.
*/
void	ra(t_list **a, t_list **b);


/*
*	Rotate b - shift up all elements of stack b by 1. 
*	The first element becomes the last one.
*/
void	rb(t_list **a, t_list **b);


/* 
*	ra and rb at the same time.
*/
void	rr(t_list **a, t_list **b);


/*
*	Reverse rotate a - shift down all elements of stack a by 1.
*	The last element becomes the first one.
*/
void	rra(t_list **a, t_list **b);

/*
*	Reverse rotate b - shift down all elements of stack b by 1.
*	The last element becomes the first one.
*/
void	rrb(t_list **a, t_list **b);


/*
*	 rra and rrb at the same time.
*/
void	rrr(t_list **a, t_list **b);

#endif