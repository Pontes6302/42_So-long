/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:43:53 by sifreita          #+#    #+#             */
/*   Updated: 2022/06/13 06:59:26 by sifreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_walls(t_main main)
{
	int	r;
	int	p;

	r = 0;
	while (r <= main.map.size.y - 1)
	{
		p = 0;
		if (r == 0 || r == main.map.size.y - 1)
		{
			while (p <= main.map.size.x - 1)
			{
				if (main.map.arr[r][p] != '1')
					error("INVALID MAP: Top or down wall not closed.\n");
				p++;
			}
		}
		if (main.map.arr[r][0] != '1' ||
				main.map.arr[r][main.map.size.x - 1] != '1')
			error("INVALID MAP: Side walls not closed.\n");
		r++;
	}
}

void	check_spawns(t_main main)
{
	int	ver[3];
	int	r;
	int	p;

	r = 1;
	ver[0] = 0;
	ver[1] = 0;
	ver[2] = 0;
	while (r < main.map.size.y - 1)
	{
		p = 1;
		while (p < main.map.size.x - 1)
		{
			if (main.map.arr[r][p] == 'P')
				ver[0] = ver[0] + 1;
			if (main.map.arr[r][p] == 'E')
				ver[1] = ver[1] + 1;
			if (main.map.arr[r][p] == 'C')
				ver[2] = ver[2] + 1;
			p++;
		}
		r++;
	}
	if (ver[0] != 1 || ver[1] != 1 || ver[2] < 1)
		error("INVALID MAP: Invalid PEC.\n");
}

void	check_char(t_main main)
{
	int	r;
	int	p;

	r = 0;
	while (r <= main.map.size.y - 1)
	{
		p = 0;
		while (p <= main.map.size.x - 1)
		{
			if (main.map.arr[r][p] != '0' && main.map.arr[r][p] != '1'
				&& main.map.arr[r][p] != 'P' && main.map.arr[r][p] != 'E'
				&& main.map.arr[r][p] != 'C')
				error("INVALID MAP: Unknown char.\n");
			p++;
		}
		r++;
	}
}

void	check_map(t_main main)
{
	int		p;
	size_t	len;

	p = 1;
	len = ft_strlen((const char *) main.map.arr[0]);
	while (main.map.arr[p] && p <= main.map.size.y - 1)
	{
		if (ft_strlen((const char *) main.map.arr[p]) != len)
			error("INVALID MAP: different line lenghts.\n");
		p++;
	}
	check_walls(main);
	check_char(main);
	check_spawns(main);
}
