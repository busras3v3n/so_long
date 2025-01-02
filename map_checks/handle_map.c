/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:09:26 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 10:12:29 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include	<stdio.h>

void	free_map_exit(t_map	*map)
{
	if (map->map_arr)
		ft_free_td(map->map_arr);
	if (map->map_arr_copy)
		ft_free_td(map->map_arr_copy);
	if (map)
		free(map);
	exit(1);
}

void	check_map_validity(t_map	*map)
{
	char	**map_cp;
	int		wall;
	int		items;
	int		rectangular;
	int		error_displayed;

	error_displayed = 0;
	map_cp = map->map_arr_copy;
	rectangular = check_rectangular(map_cp, map);
	wall = check_walls(map_cp);
	if (!rectangular)
	{
		error_msg(&error_displayed);
		write(1, "The map isn't rectangular\n", 26);
	}
	if (!wall)
	{
		error_msg(&error_displayed);
		write(1, "The map isn't surrounded by walls\n", 34);
	}
	items = check_items(map, &error_displayed);
	if (!rectangular || !wall || !items)
		free_map_exit(map);
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
		line = get_next_line(fd);
		if (!line)
			break ;
		ret = ft_join(ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

void	handle_map(char	*path, t_map *map)
{
	char	*map_string;

	map_string = make_map_string(path);
	map->map_arr = ft_split(map_string, '\n');
	map->map_arr_copy = ft_split(map_string, '\n');
	free(map_string);
	check_map_validity(map);
	check_valid_path(map);
	ft_free_td(map->map_arr_copy);
}
