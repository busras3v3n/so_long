/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:54 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 17:27:10 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map_exit(t_map	*map)
{
	if (map->map_arr)
		ft_free_td(map->map_arr);
	if (map->map_arr_copy)
		ft_free_td(map->map_arr_copy);
	if (map->map_str)
		free(map->map_str);
	if (map)
		free(map);
	exit(1);
}

void	char_count_error(t_map *map)
{
	ft_printf("Error\n");
	if(map->end_cnt > 1)
		ft_printf("more than 1 'E' on map\n");
	else if(map->end_cnt < 1)
		ft_printf("no 'E' on map\n");
	if(map->start_cnt < 1)
		ft_printf("no collectibles (C) on map");
	if(map->start_cnt > 1)
		ft_printf("more than 1 'P' on map\n");
	if(map->start_cnt < 1)
		ft_printf("no 'P' on map\n");
	free_map_exit(map);
}
