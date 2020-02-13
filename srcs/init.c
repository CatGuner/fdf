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
	im->r = 255;
	im->g = 255;
	im->b = 255;
	im->bit_per_pixel = 32;
	im->size_line = 3200;
	im->endian = 1;
	im->img_ptr = mlx_new_image(mlx_ptr, 800, 600);
	im->img_data = mlx_get_data_addr(im->img_ptr, &im->bit_per_pixel, &im->size_line, &im->endian);
}
