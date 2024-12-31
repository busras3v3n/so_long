/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:06:54 by busseven          #+#    #+#             */
/*   Updated: 2024/12/31 09:51:56 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(int	*error_displayed)
{
	if ((*error_displayed) == 0)
	{
		write(1, "Error\n", 6);
		(*error_displayed)++;
	}
}

void	check_items_help(t_map *map, int	*error_displayed)
{
	if (map->end_cnt < 1)
	{
		error_msg(error_displayed);
		write(1, "No exit (E) on map\n", 20);
	}
	if (map->end_cnt > 1)
	{
		error_msg(error_displayed);
		write(1, "More than 1 exit (E) on map\n", 29);
	}
}

int	check_items(t_map	*map, int	*error_displayed)
{
	if (map->start_cnt < 1)
	{
		error_msg(error_displayed);
		write(1, "No starting position (P) on map\n", 32);
	}
	if (map->start_cnt > 1)
	{
		error_msg(error_displayed);
		write(1, "More than 1 starting position (P) on map\n", 33);
	}
	if (map->carrot_cnt < 1)
	{
		error_msg(error_displayed);
		write(1, "No collectible(s) (C) on map\n", 30);
	}
	check_items_help(map, error_displayed);
	if (map->start_cnt == 1 && map->end_cnt == 1 && map->carrot_cnt > 0)
		return (1);
	return (0);
}
