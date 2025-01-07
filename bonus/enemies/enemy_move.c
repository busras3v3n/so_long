/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:25:11 by busseven          #+#    #+#             */
/*   Updated: 2025/01/07 12:35:42 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	check_direction_for_wall(t_enemy *cat, char **map_cp)
{
	if (cat->direction == 3)
	{
		if (is_obstacle(map_cp[cat->y / 64][(cat->x / 64) + 1]))
			return (1);
	}
	else if (cat->direction == 1)
	{
		if (is_obstacle(map_cp[cat->y / 64][(cat->x / 64)]))
			return (1);
	}
	else if (cat->direction == 0)
	{
		if (is_obstacle(map_cp[(cat->y / 64)][cat->x / 64]))
			return (1);
	}
	else if (cat->direction == 2)
	{
		if (is_obstacle(map_cp[(cat->y / 64 + 1)][(cat->x / 64)]))
			return (1);
	}
	return (0);
}

void	set_enemy_direction(t_enemy *cat, t_game *game, char **map_cp)
{
	if (cat->direction == 3 && check_direction_for_wall(cat, map_cp))
		cat->direction = rand_range_exclude(0, 3, 3, 3);
	else if (cat->direction == 1 && check_direction_for_wall(cat, map_cp))
		cat->direction = rand_range_exclude(0, 3, 1, 1);
	else if (cat->direction == 0 && check_direction_for_wall(cat, map_cp))
		cat->direction = rand_range_exclude(0, 3, 0, 0);
	else if (cat->direction == 2 && check_direction_for_wall(cat, map_cp))
		cat->direction = rand_range_exclude(0, 3, 2, 2);
	if (check_direction_for_wall(cat, map_cp))
		set_enemy_direction(cat, game, map_cp);
	if (cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
	else
		cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
}
void	set_enemy_direction2(t_enemy *cat, t_game *game, char **map_cp)
{
	if (cat->x % 64 == 0 && cat->y % 64 == 0)
		cat->direction = rand_range_exclude(0, 3, cat->direction, 6);
	else if (cat->x % 64 != 0)
		cat->direction = rand_max_exclude(3, 0, 2, cat->direction);
	else if (cat->y % 64 != 0)
			cat->direction = rand_max_exclude(3, 1, 3, cat->direction);
	if (check_direction_for_wall(cat, map_cp))
		set_enemy_direction2(cat, game, map_cp);
}

void	move_enemy(t_enemy *cat, t_game *game)
{
	char	**map_cp;

	map_cp = game->map->map_arr;
	set_enemy_direction(cat, game, game->map->map_arr);
	if (cat->direction == 0 && !check_direction_for_wall(cat, map_cp))
		cat->y -= cat->speed;
	if (cat->direction == 1 && !check_direction_for_wall(cat, map_cp))
		cat->x -= cat->speed;
	if (cat->direction == 2 && !check_direction_for_wall(cat, map_cp))
		cat->y += cat->speed;
	if (cat->direction == 3 && !check_direction_for_wall(cat, map_cp))
		cat->x += cat->speed;
	cat->counter += cat->speed;
	if (cat->counter == cat->p_len || (cat->counter > 2000 && (cat->x % 64 == 0 || cat->y % 64 == 0)))
	{
		cat->counter = 0;
		set_enemy_direction2(cat, game, game->map->map_arr);
		if (cat->direction == 1 || cat->direction == 3)
			cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
		else
			cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
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
