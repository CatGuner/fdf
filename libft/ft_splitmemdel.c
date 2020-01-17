/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmemdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:28:43 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 18:42:30 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitmemdel(char ***av, int nm)
{
	char **fav;

	fav = *av;
	if (av != NULL)
	{
		while (nm--)
		{
			ft_memdel((void*)fav);
			fav++;
		}
		*av = NULL;
	}
}
