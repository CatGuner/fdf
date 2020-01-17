/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:00:07 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 20:13:21 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitfill(char **av, const char *s, int *let, char c)
{
	int	nm;

	nm = ft_numwords(s, c);
	while (nm-- && *s)
	{
		while (*s && *s == c)
			s++;
		if ((*av = (char*)ft_memalloc(sizeof(char) * (*let + 1))))
			*av = ft_memcpy((void*)*av, (const void*)s, (size_t)*let);
		av++;
		let++;
		while (*s && *s != c)
			s++;
	}
}
