/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:59:47 by busseven          #+#    #+#             */
/*   Updated: 2024/12/28 17:16:23 by busseven         ###   ########.fr       */
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
		write(1, "Error\nInvalid characters in .ber file\n", 38);
		free_map_exit(map);
	}
}

int	check_rectangular_help(int	*k, int	*y, int *x, char **map_arr, t_map *map)
{
	while(map_arr[*y])
	{
		*k = 0;
		while(map_arr[*y][*k])
		{
			count_chars(map_arr[*y][*k], map);
			(*k)++;
		}
		if(*k != *x)
			return(0);
		(*y)++;
	}
	return(1);
}

int	check_rectangular(char **map_arr, t_map	*map)
{
	int	x;
	int	y;
	int	k;

	x = 0;
	y = 0;
	k = 0;
	if(map_arr[y])
		while(map_arr[y][x])
		{
			count_chars(map_arr[y][x], map);
			x++;
		}
	y++;
	if(!check_rectangular_help(&k, &y, &x, map_arr, map))
		return(0);
	map->width = x;
	map->height = y;
	return(1);
}

int	check_edges(int	*x, int	*y, char **map_arr)
{
	if(map_arr[*y])
	{
		while(map_arr[*y][*x])
		{
			if(map_arr[*y][*x] != '1')
				return(0);
			(*x)++;
		}
		(*y)++;
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
	
	while(map_arr[y + 1])
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
