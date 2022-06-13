/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:42:50 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 06:59:14 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_main *main)
{
	if (main->map.arr[main->player.pos.y - 1][main->player.pos.x] == 'E'
	&& main->map.cllc == 0)
		endgame(main);
	if (main->map.arr[main->player.pos.y - 1][main->player.pos.x] != '1'
	&& main->map.arr[main->player.pos.y - 1][main->player.pos.x] != 'E')
	{
		if (main->map.arr[main->player.pos.y - 1][main->player.pos.x] != 'C')
			main->map.cllc -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = '0';
		main->player.pos.y -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = 'P';
		main->player.steps++;
		main->player.path = "./images/player_up.xpm";
	}
}

void	move_left(t_main *main)
{
	if (main->map.arr[main->player.pos.y][main->player.pos.x - 1] == 'E'
	&& main->map.cllc == 0)
		endgame(main);
	if (main->map.arr[main->player.pos.y][main->player.pos.x - 1] != '1'
	&& main->map.arr[main->player.pos.y][main->player.pos.x - 1] != 'E')
	{
		if (main->map.arr[main->player.pos.y][main->player.pos.x - 1] != 'C')
			main->map.cllc -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = '0';
		main->player.pos.x -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = 'P';
		main->player.steps++;
		main->player.path = "./images/player_left.xpm";
	}
}

void	move_down(t_main *main)
{
	if (main->map.arr[main->player.pos.y + 1][main->player.pos.x] == 'E'
	&& main->map.cllc == 0)
		endgame(main);
	if (main->map.arr[main->player.pos.y + 1][main->player.pos.x] != '1'
	&& main->map.arr[main->player.pos.y + 1][main->player.pos.x] != 'E')
	{
		if (main->map.arr[main->player.pos.y + 1][main->player.pos.x] != 'C')
			main->map.cllc -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = '0';
		main->player.pos.y += 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = 'P';
		main->player.steps++;
		main->player.path = "./images/player_down.xpm";
	}
}

void	move_right(t_main *main)
{
	if (main->map.arr[main->player.pos.y][main->player.pos.x + 1] == 'E'
	&& main->map.cllc == 0)
		endgame(main);
	if (main->map.arr[main->player.pos.y][main->player.pos.x + 1] != '1'
	&& main->map.arr[main->player.pos.y][main->player.pos.x + 1] != 'E')
	{
		if (main->map.arr[main->player.pos.y][main->player.pos.x + 1] != 'C')
			main->map.cllc -= 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = '0';
		main->player.pos.x += 1;
		main->map.arr[main->player.pos.y][main->player.pos.x] = 'P';
		main->player.steps++;
		main->player.path = "./images/player_right.xpm";
	}
}

int	handle_keys(int key_pressed, t_main *main)
{
	if (key_pressed == ESC)
		close_mlx(main);
	if (key_pressed == WKEY)
		move_up(main);
	if (key_pressed == AKEY)
		move_left(main);
	if (key_pressed == SKEY)
		move_down(main);
	if (key_pressed == DKEY)
		move_right(main);
	put_map(main);
	mlx_string_put(main->win.mlx_ptr, main->win.win_ptr, 12, 12,
		0x000000, ft_itoa(main->player.steps));
	return (0);
}
