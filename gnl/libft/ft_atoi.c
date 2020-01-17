/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:14:36 by atammie           #+#    #+#             */
/*   Updated: 2019/09/19 13:20:04 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;
	unsigned long long	maxlong;
	unsigned long long	minlong;

	minlong = 9223372036854775808ULL;
	maxlong = 9223372036854775807ULL;
	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
		num = num * 10 + (*(str++) - '0') * sign;
	if (num < minlong && sign == -1)
		return (0);
	if (num > maxlong && sign == 1)
		return (-1);
	return (num);
}
