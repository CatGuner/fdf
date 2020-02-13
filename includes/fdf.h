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
	int		r;
	int		g;
	int		b;
	int		alpha;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	char    *img_data;
}               t_im;

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
	int     x1;
	int     y1;
	int     x0;
	int     y0;
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

typedef struct  s_dro
{
	int     dx;
	int     dy;
	int     error;
	int     ystep;
	int     y;
	int     x;
}               t_dro;

void        dro_line(t_coords coords, t_fdf *param);
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

#endif
