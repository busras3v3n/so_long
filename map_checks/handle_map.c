/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:09:26 by busseven          #+#    #+#             */
/*   Updated: 2025/03/12 14:54:57 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include	<stdio.h>

void	set_map_dimensions(char **map_arr, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
			x++;
		if (y == 0)
			map->width = x;
		y++;
	}
	map->height = y;
}

void	check_map_validity(t_map	*map)
{
	char	**map_cp;
	int		wall;
	int		chars;
	int		rectangular;

	map_cp = map->map_arr_copy;
	rectangular = is_rectangular(map_cp, map);
	wall = check_walls(map_cp, map);
	chars = has_valid_chars(map_cp);
	if (!rectangular || !wall || !chars)
	{
		ft_printf("Error\n");
		if (!rectangular)
			ft_printf("map must be rectangular\n");
		if (!wall)
			ft_printf("map must be surrounded by walls\n");
		if (!chars)
			ft_printf("invalid characters in map\n");
		free_map_exit(map);
	}
}

char	*make_map_string(char	*path)
{
	char	*line;
	char	*ret;
	int		fd;

	fd = open(path, O_RDWR, 0777);
	ret = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd, 1);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", ft_strlen(line)))
		{
			free(line);
			free(ret);
			get_next_line(fd, 0);
			return (NULL);
		}
		ret = ft_join(ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

void	handle_map(char	*path, t_map *map)
{
	char	*map_string;

	map->map_str = make_map_string(path);
	if (!map->map_str)
	{
		ft_printf("Error\nMap disconnected\n");
		free_map_exit(map);
	}
	map_string = map->map_str;
	map->map_arr = ft_split(map_string, '\n');
	map->map_arr_copy = ft_split(map_string, '\n');
	set_map_dimensions(map->map_arr, map);
	check_map_validity(map);
	count_chars(map->map_arr_copy, map);
	check_valid_path(map);
	ft_free_td(map->map_arr_copy);
}
