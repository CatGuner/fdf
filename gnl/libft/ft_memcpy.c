/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:59:24 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 20:13:49 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char		*ptr;
	const char	*s;

	if (dest || source)
	{
		ptr = (char*)dest;
		s = (const char*)source;
		while (n--)
			*ptr++ = *s++;
		return (dest);
	}
	return (NULL);
}
