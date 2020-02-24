#include "../includes/fdf.h"


static void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < fdf->img.w_size && y >= 0 && y < fdf->img.h_size)
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

	fst.x = fst.x * fdf->camera.zoom + fdf->img.xcent;
	fst.y = fst.y * fdf->camera.zoom + fdf->img.ycent;
	snd.x = snd.x * fdf->camera.zoom + fdf->img.xcent;
	snd.y = snd.y * fdf->camera.zoom + fdf->img.ycent;
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
	clean_im(win, 0);
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
		y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img_ptr, 0, 0);
}

static void	clean_im(t_fdf *fdf, int c)
{
	int	*image;
	int	i;

	ft_bzero(fdf->img.img_data, fdf->img.w_size * fdf->img.h_size * (fdf->img.bit_per_pixel / 8));
	i = 0;
	image = (int *)fdf->img.img_data;
	while (i < fdf->img.w_size * fdf->img.h_size)
	{
		image[i] = c;
		i++;
	}
}



static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}


