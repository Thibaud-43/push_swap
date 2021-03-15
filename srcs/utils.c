#include "sort.h"

void	check_order(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (*b)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
		
	while ((*tmp).next)
	{
		if (ft_atoi((*tmp).content) > ft_atoi((*tmp).next->content))
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("OK\n", 1);
}

void	ft_exit(t_list	*a, t_list *b)
{
	freeList(a);
	freeList(b);
	exit(0);
}

char	**get_commands_tab(void)
{
	char 	*line;
	char 	*commands;
	char	*tmp;
	int 	ret;
	char	**commands_tab;

	commands = ft_calloc(sizeof(char), 1);
	while((ret = get_next_line(0, &line)))
	{
		tmp = commands;
		commands = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		tmp = commands;
		commands = ft_strjoin(tmp, " ");
		free(tmp);
	}
	commands_tab = ft_split(commands, ' ');
	free(commands);
	return (commands_tab);
}

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