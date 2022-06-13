/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:29:26 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 06:59:30 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define ENTER 36
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2

# define PPP 32     //pixels per parcel

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include "libft.h"
# include "get_next_line.h"

//maps.c
void	check_input(int argc, char **argv);
void	map_translate(char **argv, t_main *main);
void	put_map(t_main *main);

//map_validator.c
void	check_walls(t_main main);
void	check_spawns(t_main main);
void	check_char(t_main main);
void	check_map(t_main main);

//movement.c
void	move_up(t_main *main);
void	move_left(t_main *main);
void	move_down(t_main *main);
void	move_right(t_main *main);
int		handle_keys(int key_pressed, t_main *main);

//so_long.c
void	error(char *print);
void	endgame(t_main *main);
int		close_mlx(t_main *main);
void	player_info(t_main *main);

#endif