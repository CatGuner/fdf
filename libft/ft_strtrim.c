/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:46:52 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:19:59 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned char	*str;
	unsigned char	*f;
	size_t			size;
	size_t			sp;

	if (!s)
		return (NULL);
	sp = 0;
	size = ft_strlen(s);
	while (s[sp] == '\t' || s[sp] == '\n' || s[sp] == ' ')
		sp++;
	while (s[size - 1] == '\t' || s[size - 1] == '\n' || s[size - 1] == ' ')
		size--;
	size = size - sp;
	if (&s[sp] > &s[size - 1])
		return (ft_strdup("\0"));
	if ((str = (unsigned char*)ft_strnew(sizeof(char) * (size))))
	{
		f = str;
		while (size-- != 0)
			*str++ = (unsigned char)*(sp + (s++));
		return ((char*)f);
	}
	return (NULL);
}
