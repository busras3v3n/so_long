/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:54 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 12:24:13 by busseven         ###   ########.fr       */
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
		ft_printf("Duplicate exit\n");
	else if(map->end_cnt < 1)
		ft_printf("No exit\n");
	if(map->start_cnt < 1)
		ft_printf("No collectibles\n");
	if(map->start_cnt > 1)
		ft_printf("Duplicate player\n");
	if(map->start_cnt < 1)
		ft_printf("No player\n");
	free_map_exit(map);
}
