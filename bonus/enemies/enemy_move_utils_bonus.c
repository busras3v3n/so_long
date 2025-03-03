/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:33 by busseven          #+#    #+#             */
/*   Updated: 2025/01/07 10:50:43 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_enemy_bump(t_game *game)
{
	t_enemy	**arr;
	int		i;

	i = 0;
	arr = game->cat_arr;
	while (arr[i])
	{
		if (game->map->map_arr[arr[i]->y / 64][arr[i]->x / 64] == 'P')
			reset_game(game);
		else if (game->map->map_arr[arr[i]->y / 64 + 1][arr[i]->x / 64] == 'P')
			reset_game(game);
		else if (game->map->map_arr[arr[i]->y / 64][arr[i]->x / 64 + 1] == 'P')
			reset_game(game);
		i++;
	}
}

int	rand_range(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

int	rand_range_exclude(int min, int max, int exclude, int exclude2)
{
	int	rd;

	rd = (rand() % (max - min + 1)) + min;
	if (rd == exclude || rd == exclude2)
	{
		return (rand_range_exclude(min, max, exclude, exclude2));
	}
	return (rd);
}

int	rand_max_exclude(int max, int exclude, int exclude2, int exclude3)
{
	int	rd;

	rd = (rand() % (max + 1));
	if (rd == exclude || rd == exclude2 || rd == exclude3)
	{
		return (rand_max_exclude(max, exclude, exclude2, exclude3));
	}
	return (rd);
}

int	rand_range_divides_x(int min, int max, int x)
{
	int	rd;

	rd = rand_range(min, max);
	if (x % rd != 0)
	{
		return (rand_range_divides_x(min, max, x));
	}
	return (rd);
}
