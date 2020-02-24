#include "../includes/fdf.h"

void    choose_projection(t_fdf *fdf, int key){
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	if (key == 18)
		fdf->camera.projection.f++;
	dro(fdf);
}