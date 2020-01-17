/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:10:15 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 18:42:40 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_countlet(const char *ptr, char c)
{
	int		*count;
	int		*fcount;
	char	*str;

	str = (char*)ptr;
	count = (int*)ft_memalloc(sizeof(int) * ft_numwords(ptr, c));
	fcount = count;
	while (*str != '\0')
	{
		*count = 0;
		while (*str == c && *str != '\0')
			str++;
		while (*str != c && *str != '\0')
		{
			(*count)++;
			str++;
		}
		count++;
	}
	return (fcount);
}
