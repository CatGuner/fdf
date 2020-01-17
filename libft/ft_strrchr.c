/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:10 by atammie           #+#    #+#             */
/*   Updated: 2019/09/13 21:59:11 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*k;

	i = ft_strlen((char*)s);
	while (i && s[i] != c)
		i--;
	if (!i && *s != c)
		return (NULL);
	else
		k = &s[i];
	return ((char*)k);
}
