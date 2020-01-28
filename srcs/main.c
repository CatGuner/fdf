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

void        init_coords(t_coords *coords)
{
	coords->x0 = -1;
	coords->x1 = -1;
	coords->y0 = -1;
	coords->y1 = -1;
}

int         line(int mouse, int x, int y, void *param)
{
	static t_coords     coords;
	static t_flag       flag;

	//init_coords(&coords);
	if (mouse && flag.f == 0)
	{
		coords.x0 = x;
		coords.y0 = y;
		flag.f = 1;
	}
	else if (mouse && flag.f == 1)
	{
		coords.x1 = x;
		coords.y1 = y;
		flag.f = 0;

		dro_line (coords, param);
	}

	return (0);
}

int         check_coords(t_coords *coords)
{
	int     step;

	step = abs(coords->y1 - coords->y0) > abs(coords->x1 - coords->x0);
	if (step)
	{
		ft_swap(&coords->x0, &coords->y0);
		ft_swap(&coords->x1, &coords->y1);
	}
	if (coords->x0 > coords->x1)
	{
		ft_swap(&coords->x0, &coords->x1);
		ft_swap(&coords->y0, &coords->y1);
	}
	return (step);
}

void         dro_line(t_coords coords, void *param)
{
	int     step;
	t_dro   dro;

	step = check_coords(&coords);
	dro.dx = coords.x1 - coords.x0;
	dro.dy = abs(coords.y1 - coords.y0);
	dro.error = dro.dx / 2;
	dro.ystep = (coords.y0 < coords.y1) ? 1 : -1;
	dro.y = coords.y0;
	dro.x = coords.x0;
	while (dro.x <= coords.x1)
	{
		if (step)
			mlx_pixel_put(param, param, dro.y, dro.x, 0xFFFFFF);
		else
			mlx_pixel_put(param, param, dro.x, dro.y, 0xFFFFFF);
		dro.error -= dro.dy;
		if (dro.error < 0)
		{
			dro.y += dro.ystep;
			dro.error += dro.dx;
		}
		dro.x++;
	}

}


int			deal_key(int key, void *param)
{
	if (key == 53)
		exit (0);
	ft_putnbr(key);
	ft_putchar(' ');
	return(0);

}

int			main(int ac, char **av)
{
	t_fdf   win1;
	void    *param;
	int     fd;

	fd = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY)))
			print_error();
		win1.map = NULL;
		read_file(fd, &(win1.map));
		ft_putstr(win1.map);
	//	set_sizes(&win1);
//		ft_putstr(" w ");
		//ft_putnbr(win1.wight);

	//	ft_putstr(" l ");
	//	ft_putnbr(win1.length);

		win1.mlx_ptr = mlx_init();
		win1.win_ptr = mlx_new_window(win1.mlx_ptr, 1920, 1080, "FDF");
		mlx_key_hook(win1.win_ptr, deal_key, (void *) 0);
		param = ft_memalloc(sizeof(void *) * 2);
		param = win1.win_ptr;
		mlx_mouse_hook(win1.win_ptr, line, param);
		mlx_loop(win1.mlx_ptr);
	}
}
