/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:42:42 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:23:08 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	size;

	if (ft_strlen(str))
		;
	if (!*to_find)
		return ((char*)str);
	if (!len || ft_strlen(to_find) > len)
		return (NULL);
	size = ft_strlen(to_find);
	while (*str != '\0' && len)
	{
		if (ft_strncmp(str, to_find, size) == 0)
			return ((char*)str);
		if (size >= len)
			return (NULL);
		str++;
		len--;
	}
	return (NULL);
}
