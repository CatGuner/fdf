/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:39:52 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 14:25:41 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			i;
	unsigned char	*re;
	size_t			len;

	if (s && f && (re = ft_memalloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
	{
		i = 0;
		len = ft_strlen((char*)s);
		while (i != len)
		{
			re[i] = f(s[i]);
			i++;
		}
		return ((char*)re);
	}
	return (NULL);
}
