/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:35:11 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 16:44:40 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cs1;
	char	*cs2;
	size_t	i;

	i = 0;
	cs1 = (char*)s1;
	cs2 = (char*)s2;
	if (!s1 || !s2)
		return (0);
	if ((str = ft_memalloc(ft_strlen(cs1) + ft_strlen(cs2) + 1)))
	{
		while (*cs1 != '\0')
			str[i++] = *cs1++;
		while (*cs2 != '\0')
			str[i++] = *cs2++;
		return (str);
	}
	return (0);
}
