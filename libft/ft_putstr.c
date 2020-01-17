/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:09:28 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 19:07:23 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *str)
{
	unsigned char *ptr;

	ptr = (unsigned char*)str;
	if (ptr)
	{
		while (*ptr)
			ft_putchar(*ptr++);
	}
}
