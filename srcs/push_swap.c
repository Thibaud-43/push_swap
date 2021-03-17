#include "sort.h"


void	ft_sort_list(t_list **a, t_list **b)
{
	int		size;

	size  = ft_lstsize(*a);
	if (size <= 3)
		sort_three_elem(a, b);
	else if (size <= 50)
		sort_fifty_elem(a, b);
	else
		sort_infinite_elem(a, b);

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