/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:55:53 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:52:27 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**av;
	int		nm;
	int		*let;

	if (!s)
		return (NULL);
	nm = ft_numwords(s, c);
	if (nm)
		let = ft_countlet(s, c);
	if ((av = (char**)ft_memalloc(sizeof(char*) * (nm + 1))))
	{
		if (nm)
		{
			ft_splitfill(av, s, let, c);
			ft_memdel((void**)&let);
		}
	}
	else
		ft_splitmemdel(&av, nm);
	return (av);
}
