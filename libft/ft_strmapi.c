/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:02:12 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 14:23:27 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*re;
	size_t			len;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen((char*)s);
	if ((re = ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (len--)
		{
			re[i] = f(i, s[i]);
			i++;
		}
		return (re);
	}
	return (NULL);
}
