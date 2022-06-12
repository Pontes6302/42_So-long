/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:29:21 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/12 03:22:14 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

// int follow = 1;
// int colour = 10;
// int	size = 10;

// void	my_mlx_pixel_put(t_img image, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = image.addr + (y * image.line_len + x * (image.bpp / 8));
// 	*(unsigned int *) dst = color;
// }

int	close_mlx(t_main *main)
{
        if (main)
                mlx_destroy_window (main->win.mlx_ptr, main->win.win_ptr);
        exit(EXIT_SUCCESS);
}

// int	read_keys(int key_pressed, void *param)
// {
// 	t_img *img;

// 	img = (t_img *)param;
// 	if (key_pressed == ESC || !img)
// 		exit_tutorial(&img->win);
// 	else if (key_pressed == ENTER)
// 		draw_square((t_square) {0, 0, img->w, 0xFFFFFF}, *img);
// 	else if (key_pressed == FOLLOW)
// 		follow = !follow;
// 	else if (key_pressed == COLOUR)
// 		colour = rand() % 2147483647;
// 	else
// 		return (-1);
// 	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
// }

// int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
// {
// 	t_img *img;
// 	t_square s;
// 	int x;
// 	int y;

// 	img = (t_img *)param;
// 	if (!img)
// 		return(0);
// 	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
// 		return(2);
// 	x = ((mouse_x % img->w) / size) * size;
// 	y = ((mouse_y % img->h) / size) * size;
// 	s = (t_square){x, y, size, colour};
// 	draw_square(s, *img);
// 	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
// 	(void)button;
// 	return (0);
// }

// int	continuous_read_keys(int key_pressed, void *param)
// {

// 	t_img *img;

// 	img = (t_img *)param;
// 	if (!img)
// 		exit_tutorial(&img->win);
// 	else if (key_pressed == UP)
// 	{
// 		if (size < img->w / 4)
// 			size++;
// 	}
// 	else if (key_pressed == DOWN)
// 	{
// 		if (size > 1)
// 			size--;
// 	}
// 	else if (key_pressed == RAND_COLOR)
// 		colour = rand() % 2147483647;
// 	return (0);
// }

// int follow_mouse(int mouse_x, int mouse_y, void *param)
// {
// 	int 		x;
// 	int 		y;
// 	t_img 		*img;
// 	t_square	s;

// 	img = (t_img *) param;
// 	if (!img)
// 		return (1);
// 	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
// 		return (2);
// 	if (!follow)
// 		return (3);
// 	x = ((mouse_x % img->w) / size) * size;
// 	y = ((mouse_y % img->h) / size) * size;
// 	s = (t_square){x, y, size, colour};
// 	draw_square(s, *img);
// 	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_win	tutorial;
// 	t_img	image;
// 	int size = 10;
// 	int follow = 0;

// 	tutorial = new_program(300, 300, "tutorial");
// 	image = new_image(300, 300, tutorial);
// 	draw_square((t_square){0, 0, 300, 0xFFFFFF}, image);
// 	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
// 	mlx_key_hook (tutorial.win_ptr, read_keys, &image);
// 	mlx_mouse_hook (tutorial.win_ptr, read_mouse, &image);
// 	mlx_hook(tutorial.win_ptr, 2, 0, continuous_read_keys, &image);
// 	mlx_hook(tutorial.win_ptr, 6, 0, follow_mouse, &image);
// 	mlx_hook(image.win.win_ptr, 17, 0, exit_tutorial, &image.win);
// 	mlx_loop(tutorial.mlx_ptr);
// 	return (0);
// }

// t_main	new_image(int h, int w, t_win window)
// {
// 	t_img	image;

// 	image.win = window;
// 	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
// 	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
// 	image.w = w;
// 	image.h = h;
// 	return (image);
// }

// t_win new_program(int w, int h, char *str)
// {
// 	void	*mlx_ptr;

// 	mlx_ptr = mlx_init();
// 	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
// }

int main(void)
{
	t_main	main;

	main =;
}