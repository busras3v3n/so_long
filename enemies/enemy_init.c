/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:51:46 by busseven          #+#    #+#             */
/*   Updated: 2025/01/05 12:59:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_begin_pos(t_enemy **cat, char **map, int k)
{
	int x;
	int y;

	x = 0;
	y = 0;
	k--;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'X')
			{
				if(k + 1 == 0)
				{
					(*cat)->x = x;
					(*cat)->y = y;
					return;
				}	
				k--;
			}
			x++;
		}
		y++;
	}
}
int		rand_range(int min, int max)
{
	return((rand() % (max - min + 1)) + min);
}
void	set_enemy_prop(t_enemy *cat, t_game *game)
{
	int w;
	int h;

	w = 64;
	h = 64;
	cat->direction = rand_range(0, 3);
	if(cat->direction == 0 || cat->direction == 2)
		cat->p_len = rand_range(2, game->map->height - 2);
	else if(cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(2, game->map->width - 2);
	cat->speed = 1;
	cat->cur = mlx_xpm_file_to_image(game->mlx, "./enemy_img/placeholder.xpm", &w, &h);
}
void	enemy_init(t_game *game)
{
	int k;

	game->cat_arr = ft_calloc(game->map->enemy_cnt, sizeof(t_enemy));
	k = 0;
	
	while(k < game->map->enemy_cnt)
	{
		game->cat_arr[k] = ft_calloc(1, sizeof(t_enemy));
		check_begin_pos(&game->cat_arr[k], game->map->map_arr, k);
		set_enemy_prop(game->cat_arr[k], game);
		k++;
	}
}