#include "../includes/fdf.h"

void        init_coords(t_coords *coords)
{
	coords->x0 = -1;
	coords->x1 = -1;
	coords->y0 = -1;
	coords->y1 = -1;
}

int         line(int mouse, int x, int y, t_fdf *param)
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

void         dro_line(t_coords coords, t_fdf *param)
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
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, dro.y, dro.x, 0xFFFFFF);
		else
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, dro.x, dro.y, 0xFFFFFF);
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
	return(0);
}


