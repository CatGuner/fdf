/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:41:47 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 20:35:15 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	*str;

	i = 0;
	ss = (unsigned char*)s;
	if (s && (str = ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (i != len && ss[start] != '\0')
			str[i++] = ss[start++];
		if (i != len && ss[start] == '\0')
			return (NULL);
		return ((char*)str);
	}
	return (NULL);
}
