/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:25:11 by busseven          #+#    #+#             */
/*   Updated: 2025/01/08 20:12:47 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	check_direction_for_wall(t_enemy *cat, char **map)
{
	if (cat->direction == 3)
	{
		if (is_obstacle(map[cat->y / 64][(cat->x / 64) + 1]))
			return (1);
	}
	else if (cat->direction == 1)
	{
		if (is_obstacle(map[cat->y / 64][(cat->x / 64)]))
			return (1);
	}
	else if (cat->direction == 0)
	{
		if (is_obstacle(map[(cat->y / 64)][cat->x / 64]))
			return (1);
	}
	else if (cat->direction == 2)
	{
		if (is_obstacle(map[(cat->y / 64 + 1)][(cat->x / 64)]))
			return (1);
	}
	return (0);
}

void	set_enemy_direction(t_enemy *cat, t_game *game, char **map)
{
	if (cat->direction == 3 && check_direction_for_wall(cat, map))
		cat->direction = rand_range_exclude(0, 3, 3, 3);
	else if (cat->direction == 1 && check_direction_for_wall(cat, map))
		cat->direction = rand_range_exclude(0, 3, 1, 1);
	else if (cat->direction == 0 && check_direction_for_wall(cat, map))
		cat->direction = rand_range_exclude(0, 3, 0, 0);
	else if (cat->direction == 2 && check_direction_for_wall(cat, map))
		cat->direction = rand_range_exclude(0, 3, 2, 2);
	if (check_direction_for_wall(cat, map))
		set_enemy_direction(cat, game, map);
	if (cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
	else
		cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
}
void	set_enemy_direction2(t_enemy *cat, t_game *game, char **map)
{
	if (cat->x % 64 == 0 && cat->y % 64 == 0)
		cat->direction = rand_range_exclude(0, 3, cat->direction, 6);
	else if (cat->x % 64 != 0)
		cat->direction = rand_max_exclude(3, 0, 2, cat->direction);
	else if (cat->y % 64 != 0)
			cat->direction = rand_max_exclude(3, 1, 3, cat->direction);
	if (check_direction_for_wall(cat, map))
		set_enemy_direction2(cat, game, map);
}

void	move_enemy(t_enemy *cat, t_game *game, char **map)
{
	char *path;
	int w = 64;
	int h = 64;
	set_enemy_direction(cat, game, game->map->map_arr);
	if(!check_direction_for_wall(cat, map))
	{
		if (cat->direction == 0)
			cat->y -= cat->speed;
		if (cat->direction == 1)
			cat->x -= cat->speed;
		if (cat->direction == 2)
			cat->y += cat->speed;
		if (cat->direction == 3)
			cat->x += cat->speed;
		cat->counter += cat->speed;
		cat->frame_counter += cat->speed;
	}
	if(cat->frame_counter > 32)
	{
		path = ft_calloc(22, 1);
		cat->frame_counter = 0;
		cat->frame++;
		if(cat->frame > 3)
			cat->frame = 0;
		free(cat->cur);
		snprintf(path, 22, "./enemy_img/%d/%d/%d.xpm", cat->color, cat->direction, cat->frame);
		cat->cur = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		free(path);
	}
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
		move_enemy(game->cat_arr[i], game, game->map->map_arr);
		i++;
	}
}
