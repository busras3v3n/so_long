/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:25:11 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 12:33:06 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_enemy_direction_help(t_enemy *cat)
{
	if (cat->x % 64 == 0 && cat->y % 64 == 0)
		cat->direction = rand_range_exclude(0, 3, cat->direction, 6);
	else if (cat->y % 64 == 0)
		cat->direction = rand_max_exclude(3, cat->direction, 0, 2);
	else if (cat->x % 64 == 0)
		cat->direction = rand_max_exclude(3, cat->direction, 1, 3);
	else if (cat->direction == 2 || cat->direction == 3)
		cat->direction = cat->direction - 2;
	else
		cat->direction = cat->direction + 2;
}

void	set_enemy_direction(t_enemy *cat, t_game *game, char **map)
{
	int	i;

	i = 0;
	while (check_for_wall(cat, map) || check_bump_each(cat, game->cat_arr))
	{
		if (i >= 20)
			break ;
		set_enemy_direction_help(cat);
		if (cat->freeze == 1)
			return ;
		i++;
	}
	if (cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
	else
		cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
}

void	change_pos(t_enemy *cat)
{
	if (cat->direction == 0)
		cat->y -= cat->speed;
	if (cat->direction == 1)
		cat->x -= cat->speed;
	if (cat->direction == 2)
		cat->y += cat->speed;
	if (cat->direction == 3)
		cat->x += cat->speed;
}

void	move_enemy(t_enemy *cat, t_game *game)
{
	check_surrounded(cat, game);
	if (cat->freeze == 1)
		return ;
	set_enemy_direction(cat, game, game->map->map_arr);
	if (cat->frame_counter > 15)
		animate_cat(cat, game);
	change_pos(cat);
	cat->counter += cat->speed;
	cat->frame_counter += cat->speed;
	if (cat->counter == cat->p_len || cat->counter > 2000)
	{
		if (cat->x % 64 == 0 || cat->y % 64 == 0)
		{
			cat->counter = 0;
			check_surrounded(cat, game);
			if (cat->freeze == 1)
				return ;
			set_enemy_direction_help(cat);
			set_enemy_direction(cat, game, game->map->map_arr);
		}
	}
}

void	move_all_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (game->cat_arr[i])
	{
		move_enemy(game->cat_arr[i], game);
		i++;
	}
}
