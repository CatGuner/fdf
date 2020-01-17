/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:36:56 by atammie           #+#    #+#             */
/*   Updated: 2019/09/10 13:11:38 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *ptr;
	char *fptr;
	char *g;

	g = (char*)str;
	if (str && (ptr = (char*)malloc(sizeof(char) * \
					(ft_strlen((char*)str) + 1))))
	{
		fptr = ptr;
		while (*g != '\0')
			*ptr++ = *g++;
		*ptr = '\0';
		return (fptr);
	}
	return (NULL);
}
