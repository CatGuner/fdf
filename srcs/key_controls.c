/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:43:26 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 14:45:01 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PLUS)
		fdf->camera.zoom++;
	else if (key == NUM_MINUS)
		fdf->camera.zoom--;
	if (fdf->camera.zoom < 1)
		fdf->camera.zoom = 1;
	draw(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->img.xcent -= 5;
	else if (key == ARROW_RIGHT)
		fdf->img.xcent += 5;
	else if (key == ARROW_UP)
		fdf->img.ycent -= 5;
	else
		fdf->img.ycent += 5;
	draw(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_Z)
		fdf->camera.alpha -= 0.02;
	else if (key == KEY_A)
		fdf->camera.alpha += 0.02;
	else if (key == KEY_S)
		fdf->camera.beta += 0.02;
	else if (key == KEY_X)
		fdf->camera.beta -= 0.02;
	else if (key == KEY_D)
		fdf->camera.gamma += 0.02;
	else
		fdf->camera.gamma -= 0.02;
	draw(fdf);
}

void	rise(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
		if (fdf->camera.z_dev > 10)
			fdf->camera.z_dev = 10;
		else
			fdf->camera.z_dev += 0.1;
	else
	{
		if (fdf->camera.z_dev < 0.1)
			fdf->camera.z_dev = 0.1;
		else
			fdf->camera.z_dev -= 0.1;
	}
	draw(fdf);
}

void	choose_projection(t_fdf *fdf, int key)
{
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	if (key == KEY_1)
		fdf->camera.projection.f++;
	draw(fdf);
}
