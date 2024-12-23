/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:59:47 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 13:45:37 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	count_chars(char c, t_map *map)
{
	if(c == 'C')
		map->carrot_cnt++;
	else if(c == 'E')
		map->end_cnt++;
	else if(c == 'P')
		map->start_cnt++;
	else if(c != '1' && c != '0')
	{
		write(1, "invalid elements in .ber file", 29);
		free_map_exit(map);
	}
}

void	rectangular_error(t_map *map)
{
	write(1, "the map isn't rectangular.", 26);
	free_map_exit(map);
}

void	check_rectangular(char **map_arr, t_map	*map)
{
	int	x;
	int	y;
	int	k;

	x = 0;
	y = 0;
	k = 0;
	if(map_arr[y])
		while(map_arr[y][x])
			x++;
	y++;
	while(map_arr[y])
	{
		k = 0;
		while(map_arr[y][k])
		{
			count_chars(map_arr[y][k], map);
			k++;
		}
		if(k != x)
			rectangular_error(map);
		y++;
	}
	map->width = x;
	map->height = y;
}

int	check_edges(int	*x, int	*y, char **map_arr)
{
	if(map_arr[*y])
	{
		while(map_arr[*y][*x])
		{
			if(map_arr[*y][*x] != '1')
				return(0);
			x++;
		}
		y++;
	}
	return(1);
}
int	check_walls(char	**map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	if(!check_edges(&x, &y, map_arr))
		return(0);
	while(map_arr[y + 1] && map_arr[y])
	{
		if(map_arr[y][0] != '1' || map_arr[y][x - 1] != '1')
			return(0);
		y++;
	}
	x = 0;
	if(!check_edges(&x, &y, map_arr))
		return(0);
	return(1);
}
