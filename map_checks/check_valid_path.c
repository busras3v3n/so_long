/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:19:08 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 16:41:41 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_start(t_map *map, char **map_cp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_cp[y])
	{
		x = 0;
		while (map_cp[y][x])
		{
			if (map_cp[y][x] == 'P')
			{
				map->start_x = x;
				map->start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_path(int x, int y, char **map_cp, t_map *map)
{
	if (x >= map->width || x < 0 || y >= map->height || y < 0)
		return ;
	if (map_cp[y][x] == '1')
		return ;
	else
	{
		if (map_cp[y][x] == 'C')
			map->carrot_check++;
		else if (map_cp[y][x] == 'E')
		{
			map->end_check++;
			map->exit_x = x;
			map->exit_y = y;
		}
		map_cp[y][x] = '1';
		find_path(x + 1, y, map_cp, map);
		find_path(x - 1, y, map_cp, map);
		find_path(x, y + 1, map_cp, map);
		find_path(x, y - 1, map_cp, map);
	}
}

void	check_valid_path(t_map	*map)
{
	char	**map_cp;

	map_cp = map->map_arr_copy;
	map->carrot_check = 0;
	map->end_check = 0;
	find_player_start(map, map_cp);
	find_path(map->start_x, map->start_y, map->map_arr_copy, map);
	if ((map->carrot_cnt != map->carrot_check))
	{
		write(1, "Error\nNo valid path\n", 20);
		free_map_exit(map);
	}
	else if ((map->end_cnt != map->end_check))
	{
		write(1, "Error\nNo valid path\n", 20);
		free_map_exit(map);
	}
}
