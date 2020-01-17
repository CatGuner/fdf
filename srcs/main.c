/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:49:34 by atammie           #+#    #+#             */
/*   Updated: 2020/01/17 21:08:02 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			deal_key(int key, void *param)
{
	if (key == 53)
		exit (0);
	return(0);
}

int			main()
{
	t_win win1;

	ft_putnbr(3);
	win1.mlx_ptr = mlx_init();
	win1.win_ptr = mlx_new_window(win1.mlx_ptr, 500, 500, "FDF");
	mlx_pixel_put(win1.mlx_ptr, win1.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win1.win_ptr, deal_key, (void *)0);
	mlx_loop(win1.mlx_ptr);
}
