/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:23:32 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 07:04:35 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_input(int argc, char **argv)
{
	if (argc < 2)
		error("Invalid Arguments. Write map name and extension.\n");
	else if (argc > 2)
		error("Too many arguments.\nEx: ./so_long maps/map.ber\n");
	else if (!ft_strnstr((const char *)argv[1], ".ber",
			ft_strlen((const char *)argv[1])))
		error("Invalid map extension.\n");
}

void	map_translate(char **argv, t_main *main)
{
	int	fd;
	int	p;

	p = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found.\n");
	main->map.arr = malloc(70 * sizeof(t_main));
	main->map.arr[p] = ft_strtrim((const char *)get_next_line(fd), "\n");
	while (main->map.arr[p] != NULL && p < 70)
	{
		p++;
		main->map.arr[p] = ft_strtrim((const char *)get_next_line(fd), "\n");
	}
	if (p == 0 || p == 70)
		error("INVALID MAP: Map too small/big.\n");
	main->map.size.x = (int )ft_strlen((const char *) main->map.arr[0]);
	main->map.size.y = p;
	if (main->map.size.x < 4 || main->map.size.y < 4)
		error("INVALID MAP: Map too small.\n");
	check_map(*main);
}

void	put_map_print(t_main *main, char c, int r, int p)
{
	if (c == '1')
		main->image.img_ptr = mlx_xpm_file_to_image(main->win.mlx_ptr,
				"./images/wall.xpm", &main->image.size.x, &main->image.size.y);
	if (c == '0')
		main->image.img_ptr = mlx_xpm_file_to_image(main->win.mlx_ptr,
				"./images/water.xpm", &main->image.size.x, &main->image.size.y);
	if (c == 'P')
		main->image.img_ptr = mlx_xpm_file_to_image(main->win.mlx_ptr,
				main->player.path, &main->image.size.x, &main->image.size.y);
	if (c == 'E')
		main->image.img_ptr = mlx_xpm_file_to_image(main->win.mlx_ptr,
				"./images/end.xpm", &main->image.size.x, &main->image.size.y);
	if (c == 'C')
		main->image.img_ptr = mlx_xpm_file_to_image(main->win.mlx_ptr,
				"./images/buoy.xpm", &main->image.size.x, &main->image.size.y);
	mlx_put_image_to_window(main->win.mlx_ptr, main->win.win_ptr,
		main->image.img_ptr, p * PPP, r * PPP);
	mlx_destroy_image(main->win.mlx_ptr, main->image.img_ptr);
}

void	put_map(t_main *main)
{
	int	r;
	int	p;

	r = 0;
	main->map.cllc = 0;
	while (r <= main->map.size.y - 1)
	{
		p = 0;
		while (p <= main->map.size.x - 1)
		{
			if (main->map.arr[r][p] == 'C')
				main->map.cllc += 1;
			put_map_print(main, main->map.arr[r][p], r, p);
			p++;
		}
		r++;
	}
}
