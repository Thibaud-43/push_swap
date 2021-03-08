/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trouchon <trouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:51:52 by trouchon          #+#    #+#             */
/*   Updated: 2020/11/17 15:11:51 by trouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char		*str1;
	unsigned char		*str2;
	int					i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] == str2[i] && str1[i] && str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	int					i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && n != 1 && str1[i] && str2[i])
	{
		i++;
		n--;
	}
	return (str1[i] - str2[i]);
}
