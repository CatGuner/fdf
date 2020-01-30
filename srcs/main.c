/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:49:34 by atammie           #+#    #+#             */
/*   Updated: 2020/01/17 21:08:02 by atammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int			main(int ac, char **av)
{
	t_fdf   win1;
	t_im    im1;
	void    *param;
	int     fd;
	char    **strMap;
	int     i = 0;
	int     j = 0;
	t_size  gh;

	fd = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY)))
			print_error();
		win1.map = NULL;
		read_file(fd, &win1);
	//	printf("%s", win1.map);
		win1.length = set_length(win1.map);
		win1.imap = all_atoi(&win1);
		while (i != win1.width)
		{
			j = 0;
			while (j != win1.length)
			{
				printf("%i ", win1.imap[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		gh.step = 20;
		gh.z = 10;



		win1.mlx_ptr = mlx_init();
		win1.win_ptr = mlx_new_window(win1.mlx_ptr, 1920, 1080, "FDF");
		mlx_key_hook(win1.win_ptr, deal_key, (void *) 0);
//		param = &win1;
		im1.img_ptr = mlx_new_image(win1.mlx_ptr, 300, 300);
		mlx_put_image_to_window(win1.mlx_ptr, win1.win_ptr, im1.img_ptr, 1000, 1000);
		mlx_mouse_hook(win1.win_ptr, line, &win1);
		mlx_loop(win1.mlx_ptr);
	}
}
