/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:29:26 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/12 03:06:39 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include "structs.h"

# define ESC 53
# define ENTER 36
# define FOLLOW 3
# define COLOUR 8
# define UP 126
# define DOWN 125
# define PENGUIN 35
# define RAND_COLOR 15

t_img	new_image(int h, int w, t_win window);

t_win	new_program(int w, int h, char *str);
void	my_mlx_pixel_put(t_img image, int x, int y, int color);

#endif