/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:59:47 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 16:25:22 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	count_chars(char **map_arr, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (map_arr[y][x] == 'C')
				map->carrot_cnt++;
			else if (map_arr[y][x] == 'E')
				map->end_cnt++;
			else if (map_arr[y][x] == 'P')
				map->start_cnt++;
			x++;
		}
		y++;
	}
	if (map->carrot_cnt < 1 || map->end_cnt != 1 || map->start_cnt != 1)
		char_count_error(map);
}

int	is_valid_char(char c)
{
	if (c == 'C')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c != '1' && c != '0')
		return (0);
	return (1);
}

int	has_valid_chars(char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while(map_arr[y][x])
		{
			if(!is_valid_char(map_arr[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_rectangular(char **map_arr, t_map	*map)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while(map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
			x++;
		if(x != map->width)
			return (0);
		y++;
	}
	return (1);
}

int	check_walls(char **map_arr, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[x])
		{
			if (y == 0 || y == map->height - 1)
			{
				if (map_arr[y][x] != '1')
					return (0);
			}
			else if (x == 0 || x == map->width - 1)
			{
				if (map_arr[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
