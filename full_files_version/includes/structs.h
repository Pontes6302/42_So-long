/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:58:41 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 06:38:09 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_win
{
	t_vector	size;
	void		*mlx_ptr;
	void		*win_ptr;
}	t_win;

typedef struct s_img
{
	t_vector	size;
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}	t_img;

typedef struct s_map
{
	t_vector	size;
	int			cllc;
	char		**arr;
}	t_map;

typedef struct s_player
{
	t_vector	pos;
	int			steps;
	char		*path;
}	t_player;

typedef struct s_main
{
	t_img		image;
	t_win		win;
	t_map		map;
	t_player	player;
}	t_main;

#endif