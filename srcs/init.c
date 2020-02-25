/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:32:09 by atammie           #+#    #+#             */
/*   Updated: 2020/02/13 17:38:39 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void InitImg(t_fdf* fdf)
{
	InitCamera(&fdf->camera);
	fdf->img.bit_per_pixel = 32;
	fdf->img.size_line = 3200;
	fdf->img.endian = 1;
	fdf->img.w_size = 1920;
	fdf->img.h_size = 1080;
	fdf->img.xcent = (1920 - fdf->camera.zoom * fdf->length) / 2;
	fdf->img.ycent = (1080 - fdf->camera.zoom * fdf->width) / 2;
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->img.w_size, fdf->img.h_size);
	fdf->img.img_data = mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bit_per_pixel, &fdf->img.size_line, &fdf->img.endian);
}

void InitCamera (t_camera* cam){
	cam->zoom = 5;
	cam->projection.f = 0;
	cam->z_dev = 1;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->x_offset = 0;
	cam->y_offset = 0;
}
