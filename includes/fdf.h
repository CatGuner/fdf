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

typedef struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

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

#endif
