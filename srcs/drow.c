#include "../includes/fdf.h"

t_coords    new_point(int x, int y, t_map *map)
{
	t_coords	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ?
	              get_default_color(point.z, map) : map->colors_arr[index];
	return (point);
}

static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < 800 && y >= 0 && y < 600)
	{
		i = (x * fdf->img.bit_per_pixel / 8) + (y * fdf->img.size_line);
		fdf->img.img_data[i] = color;
		fdf->img.img_data[++i] = color >> 8;
		fdf->img.img_data[++i] = color >> 16;
	}
}

int         line(int mouse, int x, int y, t_fdf *param)
{
	static t_coords     coords;
	static t_flag       flag;

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

static void         dro_line(t_coords coords, t_fdf *param)
{
	int error[2];

}

void        dro(t_fdf *param){
	int **cs = param->imap;
	int x;
	int y;
	t_coords coords;

	y = 0;
	ft_putchar('j');
	while (y != param->length){
		x = 0;
		while (x != param->width){
			if (x != param->length - 1){
				coords.x0 = x;
				coords.x1 = (x + 1);
				coords.y0 = y;
				coords.y1 = y + 1;
				dro_line(coords, param);
			}
			if (y != param->width - 1){
				coords.y0 = x;
				coords.y1 = (x + 1);
				coords.x0 = y;
				coords.x1 = y + 1;
				dro_line(coords, param);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.img_ptr, 0, 0);
}

int			deal_key(int key, void *param)
{
	if (key == 53)
		exit (0);
	return(0);
}


