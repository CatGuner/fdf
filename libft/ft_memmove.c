/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:16:45 by atammie           #+#    #+#             */
/*   Updated: 2019/09/17 21:32:12 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !source)
		return (NULL);
	d = (char*)dest;
	s = (const char*)source;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		s = s + (n - 1);
		d = d + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
