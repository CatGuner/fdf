/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:07:42 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:38:51 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	len;

	if (!*to_find)
		return ((char*)str);
	len = ft_strlen(to_find);
	while (*str)
	{
		if (ft_strncmp(str, to_find, len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
