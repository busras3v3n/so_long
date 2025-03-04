/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:05 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 17:29:12 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long_bonus.h"

void	check_lose(t_game *game)
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