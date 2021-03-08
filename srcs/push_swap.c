#include "sort.h"

void	get_list_from_argv(t_list **begin, char	**tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_lstadd_back(begin, ft_lstnew(tab[i]));
		i++;
	}
	return ;
}

void freeList(t_list	*begin)
{
   t_list	*tmp;

   while (begin != NULL)
    {
       tmp = begin;
       begin = begin->next;
       free(tmp);
    }
}

void	ft_exit(t_list	*a, t_list *b)
{
	freeList(a);
	freeList(b);
	exit(0);
}

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