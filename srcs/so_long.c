/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:29:21 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 06:59:33 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *print)
{
	write(0, print, ft_strlen((const char *)print));
	exit (EXIT_FAILURE);
}

void	endgame(t_main *main)
{
	char	*steps;

	steps = ft_itoa(main->player.steps + 1);
	write(0, "Congratulations! You've won!\n", 30);
	write(0, "You took ", 10);
	write(0, steps, sizeof(char) * ft_strlen((const char *)steps));
	write(0, " steps.\n", 8);
	mlx_destroy_window(main->win.mlx_ptr, main->win.win_ptr);
	exit (0);
}

int	close_mlx(t_main *main)
{
	if (main)
		mlx_destroy_window (main->win.mlx_ptr, main->win.win_ptr);
	exit(EXIT_SUCCESS);
}

void	player_info(t_main *main)
{
	int	r;
	int	p;

	r = 0;
	main->player.steps = 0;
	main->player.path = malloc (50 * sizeof(char));
	main->player.path = "./images/player_spawn.xpm";
	while (r <= main->map.size.y - 1)
	{
		p = 0;
		while (p <= main->map.size.x - 1)
		{
			if (main->map.arr[r][p] == 'P')
			{
				main->player.pos.x = p;
				main->player.pos.y = r;
				break ;
			}
			p++;
		}
		r++;
	}
}

int	main(int argc, char **argv)
{
	t_main	main;

	check_input(argc, argv);
	map_translate(argv, &main);
	main.win.mlx_ptr = mlx_init();
	main.win.win_ptr = mlx_new_window(main.win.mlx_ptr, main.map.size.x * PPP,
			main.map.size.y * PPP, "so_long");
	player_info(&main);
	put_map(&main);
	mlx_hook(main.win.win_ptr, 17, 0, close_mlx, &main);
	mlx_key_hook(main.win.win_ptr, handle_keys, &main);
	mlx_loop(main.win.mlx_ptr);
}
