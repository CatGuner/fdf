/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:35:39 by atammie           #+#    #+#             */
/*   Updated: 2020/02/13 17:38:59 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "../libft/libft.h"
#include <math.h>
#include "get_next_line.h"

typedef struct  s_im
{
	int		xcent;
	int		ycent;
	void	*img_ptr;
	int		color[3];
	int     w_size;
	int     h_size;
	int		alpha;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	char    *img_data;
}               t_im;

typedef struct  s_map
{
	int			width;
	int			height;
	int			*coords_arr;
	int			*colors_arr;
	int			z_min;
	int			z_max;
	int			z_range;
}               t_map;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map;
	t_im	img;
	int		**imap;
	int		length;
	int		width;
}				t_fdf;

typedef struct  s_coords
{
	int     x;
	int     y;
	int     z;
	int     color;
}               t_coords;

typedef struct  s_size
{
	int     z;
	int     step;
}               t_size;

typedef struct  s_flag
{
	unsigned char f : 1;
}               t_flag;


void        dro_line (t_coords fst, t_coords snd, t_fdf* fdf);
void        init_coords(t_coords *coords);
int         line(int mouse, int x, int y, t_fdf *param);
int         check_coords(t_coords *coords);
int			deal_key(int key, void *param);
void        print_error();
int			get_next_line(const int fd, char **line);
int         set_length(char *str);
void        read_file(int fd, t_fdf *win);
int         **all_atoi(t_fdf *win);
void		InitImg(t_im *im, void* mlx_ptr);
static void	put_pixel(t_fdf *fdf, int x, int y, int color);
void        dro(t_fdf* win);
t_coords    get_couple_coords (int x, int y);


#endif
