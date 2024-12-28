/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:19:08 by busseven          #+#    #+#             */
/*   Updated: 2024/12/28 16:22:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void up(int *x, int *y, char **map_cp, t_map *map)
{
		map_cp[*y][*x] = '1';
		(*y)--;
}
void left(int *x, int *y, char **map_cp, t_map *map)
{
		map_cp[*y][*x] = '1';
		(*x)--;
}
void down(int *x, int *y, char **map_cp)
{
		map_cp[*y][*x] = '1';
		(*y)++;
}
void right(int *x, int *y, char **map_cp)
{
		map_cp[*y][*x] = '1';
		(*x)--;
}
void		flood_fill(int x, int y, t_map *map, char **map_cp)
{
	while(map_cp[y][x])
	{
		if(map_cp[y - 1][x] != '1')
			up(&x, &y, map_cp, map);
		else if(map_cp[y][x - 1] != '1')
			left(&x, &y, map_cp, map);
		else if(map_cp[y + 1][x] != '1')
			down(&x, &y, map_cp, map);
		else if((map_cp[y][x + 1] != '1'))
			right(&x, &y, map_cp);
		else
			break ;
	}
}

void	check_valid_path(t_map	*map)
{
	char **map_cp;
	
	map_cp = map->map_arr_copy;

	int x_p = 0;
	int y_p = 0;

	while(map_cp[y_p])
	{
		x_p = 0;
		while(map_cp[y_p][x_p])
		{
			if(map_cp[y_p][x_p] == 'P')
				break ;
			x_p++;
		}
		if(map_cp[y_p][x_p] == 'P')
			break ;
		y_p++;
	}
	map->start_x = x_p;
	map->start_y = y_p;
	flood_fill(x_p, y_p, map, map_cp);
}
