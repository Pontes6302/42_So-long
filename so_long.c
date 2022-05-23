/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:23 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/23 17:34:21 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*my_mlx_pixel_put(so_data *data, int x, int y, int color)
{
	char	*conv;

	conv = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int*)conv = color;
}

void	draw_square(t_square square, so_data data)
{
	int i;
	int j;

	i = 0;
	while (i < square.size && i < data.h)
	{
		j = 0;
		while (j < square.size && j < data.w)
		{
			my_mlx_pixel_put(&data, j + square.x, i + square.y, square.coulor);
			j++;
		}
		i++;
	}
}


#include <stdio.h>
#define ESC 53
int handle_keys(int keycode, void *params) {
	printf("key: %d\n", keycode);
	if (keycode == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	so_data data;
	t_square square;
	int i;

	i = 0;
	data.wiml.mlx = mlx_init();
	data.h = 300;
	data.w = 300;
	square.x = 0;
	square.y = 0;
	square.size = 300;
	square.coulor = 0x0000FF00;
	data.wiml.win = mlx_new_window(data.wiml.mlx, 300, 300, "Hello World!");
	data.img = mlx_new_image(data.wiml.mlx, 300, 300);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_lenght, &data.endian);
	draw_square(square, data);
	mlx_put_image_to_window(data.wiml.mlx, data.wiml.win, data.img, 0, 0);
	mlx_hook(data.wiml.win, 2, 0L, handle_keys, &data);
	mlx_hook(data.wiml.win, 17, 0L, exit, &data.wiml);
	mlx_loop(data.wiml.mlx);
}
 