/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copytomas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:08:50 by atammie           #+#    #+#             */
/*   Updated: 2019/09/20 17:38:00 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copytomas(const char *str, char **av, char c)
{
	char	**fav;
	int		i;
	int		j;

	fav = av;
	i = 0;
	while (*str != '\0')
	{
		j = 0;
		while (*str != c)
			str++;
		while (*str != c && *str != '\0')
		{
			fav[i][j] = *str;
			str++;
			j++;
		}
		fav[i][j + 1] = '\0';
		i++;
	}
	fav[i] = NULL;
}
