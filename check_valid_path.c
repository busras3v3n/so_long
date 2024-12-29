/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:19:08 by busseven          #+#    #+#             */
/*   Updated: 2024/12/28 17:34:23 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	backtrack(int x, int y, char **map_cp)
{
	while()
	{
		if(1 ve V olmayan)
		else if(1 olmayan)
		else if(kalmadı?)
		else if()
		
	}
}
void	check_valid_path(t_map	*map)
{
	char **map_cp = map->map_arr_copy;

	while(map_cp[y])
	{
		x = 0;
		while(map_cp[y][x])
		{
			if(map_cp[y][x] == 'E' || map_cp[y][x] == 'C')
				backtrack(x, y, map_cp);
			x++;
		}
		y++;
	}
}
