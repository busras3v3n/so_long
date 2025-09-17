/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:05 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 19:24:30 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long_bonus.h"

void	check_lose(t_game *game)
{
	t_enemy	**arr;
	int		i;
	int		k;
	int		n;

	i = 0;
	k = 0;
	n = 0;
	arr = game->cat_arr;
	k = game->cha->y * 64;
	n = game->cha->x * 64;
	while (arr[i])
	{
		int dx = abs(arr[i]->x - n);
		int dy = abs(arr[i]->y - k);
		if(dy < 64 && dx < 64)
		{
			if(game->cha->killer == 0)
				reset_game(game);
			else
				arr[i]->dead = 1;
		}
		i++;
	}
}
