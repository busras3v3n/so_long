/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:59:47 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 11:50:50 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

void	check_valid_char(char c, t_map *map)
{
	if (c == 'C')
		map->carrot_cnt++;
	else if (c == 'E')
		map->end_cnt++;
	else if (c == 'P')
		map->start_cnt++;
	else if (c != '1' && c != '0')
	{
		write(1, "Error\nInvalid characters in .ber file\n", 38);
		free_map_exit(map);
	}
}

int	look_for_invalid_chars()

int	check_rectangular(char **map_arr, t_map	*map)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while(map_arr[0][x])
		x++;
	map->width = x + 1;
	x = 0;
	while(map_arr[y])
	{
		x = 0;
		while(map_arr[y][x])
			x++;
		if(x != map->width - 1)
			return (0);
		y++;
	}
	map->height = y + 1;
	return (1);
}

int	check_walls(char	**map_arr, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while(map_arr[y])
	{
		x = 0;
		while(map_arr[x])
		{
			if (y == 0 || y == map->height - 1)
			{
				if (x != 1)
					return (0);
			}
			else if (x == 0 || x == map->width - 1)
			{
				if(x != 1)
					return (0);
			}
			x++;
		}
		y++;
	}
}
