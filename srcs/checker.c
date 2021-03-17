#include "sort.h"

void    printnumber(char * str, t_list *a, t_list *b)
{
	t_list	*tmpa;
	t_list	*tmpb;

	tmpa = a;
	tmpb = b;

	printf("\e[H\e[2J");
	printf("\33[1;34m");
	printf("\n\n     -----------------\n");
	printf("    | COMMAND : %5s | \n", str);
	printf("     -----------------\n\n");
	printf("\033[0m");
    printf("%11c  |  %-11c\n", 'A', 'B');
	printf("         ----------\n");

    while (a || b)
    {
        if (a)
        {
			printf("\33[1;35m");
            printf(" %11s  ", (char *)a->content);
			printf("\033[0m");
            a = a->next;
        }
        else
		{
			
			printf(" %11s  ", "");
		}
        if (b)
        {
			printf("\33[1;33m");
            printf(" %-11s", (char *)b->content);
			printf("\033[0m");
            b = b->next;
        }
        printf("\n");
    }
	a = tmpa;
	b = tmpb;
}

static int	apply_commands(t_list **a, t_list **b, char **commands)
{
	int i;
	i = 0;

	
	while (commands[i])
	{
		if (!ft_strcmp(commands[i], "sa"))
		{
			sa(a, b);
			printnumber("sa", *a, *b);
		}	
		else if (!ft_strcmp(commands[i], "sb"))
		{
			sb(a, b);
			printnumber("sb", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "pa"))
		{
			pa(a, b);
			printnumber("pa", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "pb"))
		{
			pb(a, b);
			printnumber("pb", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "ra"))
		{
			ra(a, b);
			printnumber("ra", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "rb"))
		{
			rb(a, b);
			printnumber("rb", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "rra"))
		{
			rra(a, b);
			printnumber("rra", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "rrb"))
		{
			rrb(a, b);
			printnumber("rrb", *a, *b);
		}
		else if (!ft_strcmp(commands[i], "rrr"))
		{
			rrr(a, b);
			printnumber("rrr", *a, *b);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		usleep(500000);
		i++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char		**commands;
	t_list		*a;
	t_list		*b;
	
	a = NULL;
	b = NULL;
	commands = get_commands_tab();
	get_list_from_argv(&a, (char **)argv + 1);
	if (apply_commands(&a, &b, commands))
		ft_exit(a, b);
	check_order(&a, &b);
	ft_exit(a, b);	
	return 0;
}