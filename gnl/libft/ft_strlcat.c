/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:05:28 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 21:39:22 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char*)src);
	if (dstlen >= size)
		return (size + srclen);
	if (srclen + dstlen < size)
		ft_strcat(dst, src);
	else
		ft_strncat(dst, src, size - dstlen - 1);
	return (dstlen + srclen);
}
