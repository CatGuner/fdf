/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:32:52 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 21:58:25 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *arr1, const char *arr2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)arr1;
	s2 = (unsigned char*)arr2;
	if (!n)
		return (0);
	while (n && (*s1 && *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n > 1)
		{
			s1++;
			s2++;
		}
		n--;
	}
	return (*s1 - *s2);
}
