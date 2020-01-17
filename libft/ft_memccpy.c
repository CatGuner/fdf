/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:05:37 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:25:30 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*s;

	ptr = (unsigned char*)dest;
	s = (unsigned char*)source;
	while (n--)
	{
		*ptr = *s;
		if (*s == (unsigned char)c)
			return (++ptr);
		ptr++;
		s++;
	}
	return (NULL);
}
