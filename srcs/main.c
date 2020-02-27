/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:49:34 by atammie           #+#    #+#             */
/*   Updated: 2020/02/13 17:39:02 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

int			main(int ac, char **av)
{
	t_fdf   win1;
	int     fd;

	fd = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY)))
			print_error();
		win1.map = NULL;
		read_file(fd, &win1);
		win1.length = set_length(win1.map);
		win1.imap = all_atoi(&win1);
		win1.mlx_ptr = mlx_init();
		win1.win_ptr = mlx_new_window(win1.mlx_ptr, 1920, 1080, "FDF");
		InitImageAndCamera(&win1);
		draw(&win1);
		setup_controls(&win1);
		mlx_loop(win1.mlx_ptr);
	}
}
