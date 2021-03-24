/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:27:36 by trouchon          #+#    #+#             */
/*   Updated: 2021/01/27 13:57:42 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void			init_flags(t_flags *flags)
{
	flags->display = 0;
	flags->color = 0;
	flags->file_redir_dst = 1;
	flags->file_redir_src = 0;
	flags->help = 0;
	flags->time = 50000;
}

static void			print_help(t_flags *flags)
{
	ft_putstr_fd("\nLISTE DES FLAGS DISPO POUR CHECKER :\n", 1);
	ft_putstr_fd("\t -d : activer l'affichage des stacks\n", 1);
	ft_putstr_fd("\t -c : afficher en couleur\n", 1);
	ft_putstr_fd("\t -t : temps d'attente entre chaque "
	"commande en milliseconde\n", 1);
	ft_putstr_fd("\t -src [file]: lire a partir du fichier\n\n", 1);
	ft_putstr_fd("LISTE DES FLAGS DISPO POUR PUSH SWAP :\n", 1);
	ft_putstr_fd("\t -dst [file]: ecrire sur un fichier\n\n", 1);
	if (flags->file_redir_dst > 1)
		close(flags->file_redir_dst);
	if (flags->file_redir_src > 1)
		close(flags->file_redir_src);
	exit(0);
}

static void			check_flags3(char **argv, t_flags *flags, int *i, int *ret)
{
	if (!ft_strcmp(argv[*i], "-t"))
	{
		(*ret)++;
		(*i)++;
		flags->time = ft_atoi(argv[*i]);
		(*ret)++;
	}
}

static void			check_flags2(char **argv, t_flags *flags, int *i, int *ret)
{
	if (!ft_strcmp(argv[*i], "-c"))
	{
		(*ret)++;
		flags->color = 1;
	}
	if (!ft_strcmp(argv[(*i)], "--dst"))
	{
		(*ret)++;
		(*i)++;
		flags->file_redir_dst = open(argv[*i], O_RDWR | O_CREAT, S_IRWXU);
		(*ret)++;
	}
	if (!ft_strcmp(argv[(*i)], "--src"))
	{
		(*ret)++;
		(*i)++;
		flags->file_redir_src = open(argv[*i], O_RDWR);
		(*ret)++;
	}
}

int					check_flags(char **argv, t_flags *flags)
{
	int		i;
	int		ret;

	ret = 1;
	i = 0;
	init_flags(flags);
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-h"))
		{
			ret++;
			print_help(flags);
			flags->help = 1;
		}
		if (!ft_strcmp(argv[i], "-d"))
		{
			ret++;
			flags->display = 1;
		}
		check_flags2(argv, flags, &i, &ret);
		check_flags3(argv, flags, &i, &ret);
		i++;
	}
	return (ret);
}
