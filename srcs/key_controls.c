#include "../includes/fdf.h"

int     key_press (int keycode, void *param){
	t_fdf* ll;
	ll = (t_fdf *)param;
	if (keycode == ESC){
		exit (0);
	}
	else if (keycode == NUM_PLUS || keycode == NUM_MINUS)
		zoom(keycode, ll);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		move(keycode, ll);
	else if ((keycode >= KEY_Z && keycode <= KEY_C) ||
			(keycode >= KEY_A && keycode <= KEY_D))
		rotate(keycode, ll);
	else if (keycode == KEY_1)
		choose_projection(ll, keycode);
	return (0);
}


void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PLUS)
		fdf->camera.zoom++;
	else if (key == NUM_MINUS)
		fdf->camera.zoom--;
	if (fdf->camera.zoom < 1)
		fdf->camera.zoom = 1;
	dro(fdf);
}

void    move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->img.xcent -= 5;
	else if (key == ARROW_RIGHT)
		fdf->img.xcent += 5;
	else if (key == ARROW_UP)
		fdf->img.ycent -= 5;
	else
		fdf->img.ycent += 5;
	dro(fdf);
}

void    rotate(int key, t_fdf *fdf)
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
	dro(fdf);
}

int			setup_controls(t_fdf *param)
{
	mlx_hook(param->win_ptr, 2, 0, key_press, param);
	return(0);
}