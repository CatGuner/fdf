/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:22:17 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 22:14:56 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_num(int nb, char *f)
{
	int	k;

	if (nb / 10 != 0)
		rec_num(nb / 10, f - 1);
	k = nb % 10;
	if (k < 0)
		k = -k;
	*f = k + '0';
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		kk;
	size_t	len;

	kk = n;
	len = 0;
	while (kk != 0)
	{
		len++;
		kk = kk / 10;
	}
	if (n <= 0)
		len++;
	if ((nbr = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		nbr[len] = '\0';
		if (n < 0)
			nbr[0] = '-';
		rec_num(n, nbr + len - 1);
		return (nbr);
	}
	return (NULL);
}
