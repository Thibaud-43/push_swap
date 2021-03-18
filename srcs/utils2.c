#include "sort.h"

void	ft_init_tab(int *tab, int size)
{
	int i;

	i = 0;
	
	while (size)
	{
		tab[i] = 0;
		i++;
		size--;
	}
}

int		ft_is_in_tab(int nb, int *tab, int size)
{
	int i;

	i = 0;
	
	while (size)
	{
		if (nb == tab[i] && nb != 0)
			return (1);
		i++;
		size--;
	}
	return (0);
}

int		check_double(t_list **a)
{
	int size;
	int	*tab;
	int nb;
	int	i;
	t_list	*tmp;

	tmp = *a;
	size = ft_lstsize(*a);
	i = 0;
	if (!(tab = malloc(sizeof(int) * size)))
		return (1);
	ft_init_tab(tab, size);
	while (tmp)
	{
		nb = ft_atoi((char *)tmp->content);
		if (ft_is_in_tab(nb, tab, size))
			return (1);
		else
		{
			tab[i] = ft_atoi((char *)tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
	return (0);
}