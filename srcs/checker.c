#include "sort.h"

void	print_lists(t_list	*a, t_list	*b)
{
	printf("\n List A : \n");
	ft_lstprint(a);
	printf("\n List B : \n");
	ft_lstprint(b);
	printf("\n");
}

static int	apply_commands(t_list **a, t_list **b, char **commands)
{
	int i;
	i = 0;

	while (commands[i])
	{
		if (!ft_strcmp(commands[i], "sa"))
			sa(a, b);
		else if (!ft_strcmp(commands[i], "sb"))
			sb(a, b);
		else if (!ft_strcmp(commands[i], "pa"))
			pa(a, b);
		else if (!ft_strcmp(commands[i], "pb"))
			pb(a, b);
		else if (!ft_strcmp(commands[i], "ra"))
			ra(a, b);
		else if (!ft_strcmp(commands[i], "rb"))
			rb(a, b);
		else if (!ft_strcmp(commands[i], "rra"))
			rra(a, b);
		else if (!ft_strcmp(commands[i], "rrb"))
			rrb(a, b);
		else if (!ft_strcmp(commands[i], "rrr"))
			rrr(a, b);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char	**commands;
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	commands = get_commands_tab();
	get_list_from_argv(&a, (char **)argv + 1);
	if (apply_commands(&a, &b, commands))
		ft_exit(a, b);
	check_order(&a, &b);
	print_lists(a, b);
	ft_exit(a, b);	
	return 0;
}