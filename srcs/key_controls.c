#include "../includes/fdf.h"

int     key_press (int keycode, void *param){
	t_fdf* ll;
	ll = (t_fdf *)param;
	if (keycode == 53){
		exit (0);
	}
	else if (keycode == 69 || keycode == 78)
		zoom(keycode, ll);
	return (0);
}
//
//int     key_release (int keycode, t_fdf *param){
//
//}

void	zoom(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->camera.zoom++;
	else if (key == 78)
		fdf->camera.zoom--;
	if (fdf->camera.zoom < 1)
		fdf->camera.zoom = 1;
	dro(fdf);
}

int			setup_controls(t_fdf *param)
{
	mlx_hook(param->win_ptr, 2, 0, key_press, param);
	return(0);
}