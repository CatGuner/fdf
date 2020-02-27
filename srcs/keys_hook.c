/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:45:46 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 14:46:45 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_press(int keycode, void *param)
{
	t_fdf	*ll;

	ll = (t_fdf *)param;
	if (keycode == ESC)
		exit(0);
	else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
		zoom(keycode, ll);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		move(keycode, ll);
	else if ((keycode >= KEY_Z && keycode <= KEY_C) ||
			(keycode >= KEY_A && keycode <= KEY_D))
		rotate(keycode, ll);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		rise(keycode, ll);
	else if (keycode == KEY_1)
		choose_projection(ll, keycode);
	return (0);
}

int			setup_controls(t_fdf *param)
{
	mlx_hook(param->win_ptr, 2, 0, key_press, param);
	return (0);
}
