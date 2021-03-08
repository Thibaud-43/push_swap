#include "sort.h"

int main(int argc, char const *argv[])
{
	char	**commands;
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	get_list_from_argv(&a, (char **)argv + 1);
	
	ft_exit(a, b);	
	return 0;
}