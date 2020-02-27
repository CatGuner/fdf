/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:16 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 16:19:47 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coords		get_coords(int x, int y, t_fdf *fdf)
{
	t_coords	point;

	point.x = x * fdf->camera.zoom;
	point.y = y * fdf->camera.zoom;
	point.z = fdf->imap[y][x];
	return (point);
}

void			draw(t_fdf *win)
{
	int			x;
	int			y;

	y = 0;
	clean_im(win);
	while (y < win->width)
	{
		x = 0;
		while (x < win->length)
		{
			if (x != win->length - 1)
				draw_line(projection(get_coords(x, y, win), win),
						projection(get_coords(x + 1, y, win), win), win);
			if (y != win->width - 1)
				draw_line(projection(get_coords(x, y, win), win),
						projection(get_coords(x, y + 1, win), win), win);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
}

static void		clean_im(t_fdf *fdf)
{
	int			*image;
	int			i;

	ft_bzero(fdf->img.img_data,
			fdf->img.w_size * fdf->img.h_size * (fdf->img.bit_per_pixel / 8));
	i = 0;
	image = (int *)fdf->img.img_data;
	while (i < fdf->img.w_size * fdf->img.h_size)
	{
		image[i] = 0;
		i++;
	}
}

static void		iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
