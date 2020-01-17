/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:01:52 by atammie           #+#    #+#             */
/*   Updated: 2019/09/13 18:14:37 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numwords(const char *ptr, char sep)
{
	char	*str;
	int		count;

	str = (char*)ptr;
	count = 0;
	while (*str != '\0')
	{
		while (*str == sep)
			str++;
		if (*str != sep && *str != '\0')
			count++;
		while (*str != sep && *str != '\0')
			str++;
	}
	return (count);
}
