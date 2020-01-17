/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:04:03 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 20:14:28 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*ptr;
	size_t			len;

	s = (unsigned char *)src;
	ptr = (unsigned char *)dest;
	len = ft_strlen(src);
	ptr = ft_memcpy(ptr, s, n);
	if (n > len)
		ft_bzero((ptr + len), n - len);
	return (dest);
}
