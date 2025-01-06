/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:51:46 by busseven          #+#    #+#             */
/*   Updated: 2025/01/06 09:24:28 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <time.h>

void	check_begin_pos(t_enemy *cat, char **map, int k)
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
					(cat)->x = x * 64;
					(cat)->y = y * 64;
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
	cat->speed = 5;
	cat->counter = 0;
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
		check_begin_pos(game->cat_arr[k], game->map->map_arr, k);
		set_enemy_prop(game->cat_arr[k], game);
		k++;
	}
}
void	check_enemy_bump(t_game *game)
{
	t_enemy **arr;
	int i;

	i = 0;
	arr = game->cat_arr;

	while(arr[i])
	{
		if (game->map->map_arr[arr[i]->y/64][arr[i]->x/64] == 'P')
			reset_game(game);
		else if (game->map->map_arr[arr[i]->y/64 + 1][arr[i]->x/64] == 'P')
			reset_game(game);
		else if (game->map->map_arr[arr[i]->y/64][arr[i]->x/64 + 1] == 'P')
			reset_game(game);
		i++;
	}
}
void	set_enemy_direction(t_enemy *cat, t_game *game)
{
	char **map_cp;

	map_cp = ft_split(game->map->map_str, '\n');
	if ((cat->direction == 3 && map_cp[cat->y / 64][(cat->x / 64) + 1] == '1'))
	{
		cat->direction = 1;
		return ;
	}
	else if((cat->direction == 1 && map_cp[cat->y / 64][(cat->x / 64)] == '1'))
	{
		cat->direction = 3;
		return ;
	}
	else if(cat->direction == 0 && map_cp[(cat->y / 64)][cat->x / 64] == '1')
	{
		cat->direction = 2;
		return ;
	}
	else if(cat->direction == 2 && map_cp[(cat->y / 64 + 1)][(cat->x / 64)] == '1')
	{
		cat->direction = 0;
		return ;
	}
}

void	move_enemy(t_enemy *cat, t_game *game)
{
	set_enemy_direction(cat, game);
	if(cat->direction == 0)
		cat->y-=cat->speed;
	if(cat->direction == 1)
		cat->x-=cat->speed;
	if(cat->direction == 2)
		cat->y+=cat->speed;
	if(cat->direction == 3)
		cat->x+=cat->speed;
	cat->counter-= cat->speed;
}
void	move_all_enemies(t_game *game)
{
	int i;

	i = 0;
	while(game->cat_arr[i])
	{
		move_enemy(game->cat_arr[i], game);
		i++;
	}
}
int	update_game(t_game *game)
{
	if (++game->delay % 5000 == 0)
    {
		move_all_enemies(game);
		draw_map(game);
		if(game->win_condition == 0)
			check_enemy_bump(game);
    }
	return(0);
}