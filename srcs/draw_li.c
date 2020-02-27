/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_li.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:10:18 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 14:36:40 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < fdf->img.w_size && y >= 0 && y < fdf->img.h_size)
	{
		i = (x * fdf->img.bit_per_pixel / 8) + (y * fdf->img.size_line);
		fdf->img.img_data[i] = color;
		fdf->img.img_data[++i] = color;
		fdf->img.img_data[++i] = color;
	}
}

void			draw_line(t_coords fst, t_coords snd, t_fdf *fdf)
{
	t_coords	delta;
	t_coords	sign;
	t_coords	cure;
	int			error[2];

	delta.x = abs(fst.x - snd.x);
	delta.y = abs(fst.y - snd.y);
	sign.x = fst.x < snd.x ? 1 : -1;
	sign.y = fst.y < snd.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cure = fst;
	while (cure.x != snd.x || cure.y != snd.y)
	{
		put_pixel(fdf, cure.x, cure.y, 0xFFFFFF);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cure.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cure.y += sign.y;
		}
	}
}
