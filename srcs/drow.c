#include "../includes/fdf.h"


static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < 800 && y >= 0 && y < 600)
	{
		i = (x * fdf->img.bit_per_pixel / 8) + (y * fdf->img.size_line);
		fdf->img.img_data[i] = color;
		fdf->img.img_data[++i] = color;
		fdf->img.img_data[++i] = color;
	}
}

void        dro_line (t_coords fst, t_coords snd, t_fdf* fdf)
{
	t_coords    delta;
	t_coords    sign;
	t_coords    cure;
	int         error[2];

	fst.x = fst.x * 20 + 200;
	fst.y = fst.y * 20 + 200;
	snd.x = snd.x * 20 + 200;
	snd.y = snd.y * 20 + 200;
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

t_coords    get_couple_coords (int x, int y)
{
	t_coords point;

	point.x = x;
	point.y = y;

	return (point);
}

void        dro(t_fdf* win)
{
	int		x;
	int		y;

	y = 0;
	while (y < win->length)
	{
		x = 0;
		while (x < win->width)
		{
			if (x != win->width - 1)
				dro_line(get_couple_coords(x, y), get_couple_coords(x + 1, y), win);

			if (y != win->length - 1)
				dro_line(get_couple_coords(x, y), get_couple_coords(x, y + 1), win);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
}

int			deal_key(int key, void *param)
{
	if (key == 53)
		exit (0);
	return(0);
}


