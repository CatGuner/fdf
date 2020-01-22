/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:35:39 by atammie           #+#    #+#             */
/*   Updated: 2020/01/17 19:47:50 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "../libft/libft.h"
#include <math.h>
#include "get_next_line.h"

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	char    *map;
	int     **imap;
	int     length;
	int     wight;
}				t_fdf;

typedef struct  s_coords
{
	int     x1;
	int     y1;
	int     x0;
	int     y0;
}               t_coords;

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

void        dro_line(t_coords coords, void *param);
void        init_coords(t_coords *coords);
int         line(int mouse, int x, int y, void *param);
int         check_coords(t_coords *coords);
int			deal_key(int key, void *param);
void        print_error();
int			get_next_line(const int fd, char **line);
void        set_sizes(t_fdf *win);
void        read_file(int fd, char **tmp);

#endif
