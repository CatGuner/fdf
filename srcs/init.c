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

void InitImg(t_im* im, void* mlx_ptr)
{
	im->color[0] = 255;
	im->color[1] = 255;
	im->color[2] = 255;
	im->xcent = 590;
	im->ycent = 240;
	im->bit_per_pixel = 32;
	im->size_line = 3200;
	im->endian = 1;
	im->w_size = 800;
	im->h_size = 600;
	im->img_ptr = mlx_new_image(mlx_ptr, im->w_size, im->h_size);
	im->img_data = mlx_get_data_addr(im->img_ptr, &im->bit_per_pixel, &im->size_line, &im->endian);
}
