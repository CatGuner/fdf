/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:38:39 by atammie           #+#    #+#             */
/*   Updated: 2019/09/10 18:48:38 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *first;

	first = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && n-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (first);
}
