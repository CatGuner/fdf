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


int			main(int ac, char **av)
{
	t_fdf   win1;
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
		win1.imap = all_atoi(&win1); //переводим карту в интовую матрицу

		// проверка на правильность перевода в int
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


		win1.mlx_ptr = mlx_init();
		win1.win_ptr = mlx_new_window(win1.mlx_ptr, 1920, 1080, "FDF");
		mlx_key_hook(win1.win_ptr, deal_key, (void *) 0);
		InitImg(&win1.img, win1.mlx_ptr);
		dro(&win1);

	//	mlx_mouse_hook(win1.win_ptr, line, &win1);
		mlx_loop(win1.mlx_ptr);
	}
}
