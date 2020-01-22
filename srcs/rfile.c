/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:18:59 by atammie           #+#    #+#             */
/*   Updated: 2020/01/22 17:19:02 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        set_sizes(t_fdf *win)
{
	int     max;
	int     i;
	char    *tmp;

	tmp = win->map;
	ft_putstr(tmp);
	i = 0;
	max = 0;
	while (*tmp != '\0')
	{
		while (*tmp != '\n' || *tmp != '\0')
		{
			max++;
			tmp++;
		}
		if (i == 0)
			win->length = max;
		else if (max != win->length)
			print_error();
		i++;
		tmp++;
	}
	win->wight = i;
}

void        read_file(int fd, char **tmp)
{
	while ((get_next_line(fd, tmp)) > 0) {
		ft_putstr(*tmp);
		continue;
	}

}
