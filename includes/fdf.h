/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:35:39 by atammie           #+#    #+#             */
/*   Updated: 2020/02/27 18:04:53 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <math.h>
# include "../libft/get_next_line.h"
# include "key_macros.h"

typedef struct	s_flag
{
	unsigned char f : 1;
}				t_flag;

typedef struct	s_im
{
	int			xcent;
	int			ycent;
	void		*img_ptr;
	int			color[3];
	int			w_size;
	int			h_size;
	int			alpha;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	char		*img_data;
}				t_im;

typedef struct	s_camera
{
	t_flag		projection;
	int			zoom;
	double		alpha;
	double		beta;
	double		gamma;
	float		z_dev;
	int			x_offset;
	int			y_offset;
}				t_camera;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map;
	t_im		img;
	t_camera	camera;
	int			**imap;
	int			length;
	int			width;
}				t_fdf;

typedef struct	s_coords
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_coords;

typedef struct	s_size
{
	int			z;
	int			step;
}				t_size;

void			draw_line(t_coords fst, t_coords snd, t_fdf *fdf);
void			init_coords(t_coords *coords);
int				line(int mouse, int x, int y, t_fdf *param);
int				check_coords(t_coords *coords);
int				setup_controls (t_fdf *param);
void			print_error();
int				get_next_line(const int fd, char **line);
int				set_length(char *str);
void			read_file(int fd, t_fdf *win);
int				**all_atoi(t_fdf *win);
void			init_image_and_camera(t_fdf *fdf);
void			init_camera(t_camera *cam);
static void		put_pixel(t_fdf *fdf, int x, int y, int color);
void			draw(t_fdf *win);
t_coords		get_coords (int x, int y, t_fdf *fdf);
static void		clean_im(t_fdf *fdf);
int				key_press (int keycode, void *param);
int				key_release (int keycode, t_fdf *param);
void			zoom(int key, t_fdf *fdf);
static void		iso(int *x, int *y, int z);
void			choose_projection(t_fdf *fdf, int key);
t_coords		projection(t_coords c, t_fdf *fdf);
static void		rotate_x(int *y, int *z, double alpha);
static void		rotate_y(int *x, int *z, double beta);
static void		rotate_z(int *x, int *y, double gamma);
void			move(int key, t_fdf *fdf);
void			rotate(int key, t_fdf *fdf);
void			rise(int key, t_fdf *fdf);

#endif
