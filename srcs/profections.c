#include "../includes/fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
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

t_coords projection(t_coords c, t_fdf *fdf){
	c.x = c.x * fdf->camera.zoom;
	c.y = c.y * fdf->camera.zoom;
	c.z = c.z * fdf->camera.zoom * fdf->camera.z_dev;
	rotate_x(&c.y, &c.z, fdf->camera.alpha);
	rotate_y(&c.x, &c.z, fdf->camera.beta);
	rotate_z(&c.x, &c.y, fdf->camera.gamma);
	if (fdf->camera.projection.f)
		iso(&c.x, &c.y, c.z);
	return (c);
}