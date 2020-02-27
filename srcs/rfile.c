/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:18:59 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 16:07:01 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		read_file(int fd, t_fdf *win)
{
	char	*ptr;
	char	*tmp;

	tmp = ft_strnew(0);
	win->width = 0;
	while ((get_next_line(fd, &ptr)) > 0)
	{
		ft_strcat(ptr, "\n");
		win->width++;
		tmp = ft_strjoin(tmp, ptr);
	}
	win->map = tmp;
}

int			set_length(char *str)
{
	int		count;
	int		ic;

	ic = 0;
	count = 0;
	while (*str != '\0')
	{
		while ((ft_isdigit(*str)) || *str == '-')
			str++;
		count++;
		while (*str != '\0' && (*str == ' ' || *str == '\t'))
			str++;
		if (*str == '\n')
		{
			if (ic != 0 && ic != count)
				print_error();
			ic = count;
			count = 0;
		}
		str++;
	}
	return (ic);
}

int			**all_atoi(t_fdf *win)
{
	int		**int_map;
	int		x;
	int		y;
	char	*tmp;

	y = 0;
	tmp = win->map;
	int_map = (int**)malloc(sizeof(int*) * (win->width + 1));
	int_map[win->width + 1] = NULL;
	while (y != win->width)
	{
		int_map[y] = (int*)malloc(sizeof(int) * win->length);
		x = 0;
		while (x != win->length)
		{
			while (*tmp != '\0' && (!ft_isdigit(*tmp) && *tmp != '-'))
				tmp++;
			int_map[y][x] = (ft_atoi(tmp));
			while (*tmp != '\0' && (ft_isdigit(*tmp) || *tmp == '-'))
				tmp++;
			x++;
		}
		y++;
	}
	return (int_map);
}
