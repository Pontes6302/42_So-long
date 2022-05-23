/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:27:18 by sifreita          #+#    #+#             */
/*   Updated: 2022/05/21 21:39:57 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

typedef struct mlxsave
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	mlxsave;

typedef struct so_long
{
	mlxsave wiml;
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_lenght;
	int		endian;
}	so_data;

typedef struct square
{
	int x;
	int y;
	int size;
	int coulor;
}	t_square;


#endif