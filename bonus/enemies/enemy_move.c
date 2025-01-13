/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:25:11 by busseven          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int check_enemy_bump_left(t_enemy *cat, t_enemy *cat2)
{
	if(cat != cat2)
	{
		if(cat->x  > cat2->x)
		{
			if(cat->y - cat2->y > -64 && cat->y - cat2->y < 64)
			{
				if(cat->x - cat->speed < cat2->x + 64)
					return (1);
			}
		}
	}
	return (0);
}
int check_enemy_bump_down(t_enemy *cat, t_enemy *cat2)
{
	if(cat != cat2)
	{
		if(cat->y < cat2->y)
		{
			if(cat->x - cat2->x > -64 && cat->x - cat2->x < 64)
			{
				if(cat->y + cat->speed > cat2->y - 64)
					return (1);
			}
		}
	}
	return (0);
}
int check_enemy_bump_right(t_enemy *cat, t_enemy *cat2)
{
	if(cat != cat2)
	{
		if(cat->x < cat2->x)
		{
			if(cat->y - cat2->y > -64 && cat->y - cat2->y < 64)
			{
				if(cat->x + cat->speed > cat2->x - 64)
					return (1);
			}
		}
	}
	return (0);
}
int check_enemy_bump_up(t_enemy *cat, t_enemy *cat2)
{
	if(cat != cat2)
	{
		if(cat->y > cat2->y)
		{
			if(cat->x - cat2->x > -64 && cat->x - cat2->x < 64)
			{
				if(cat->y - cat->speed < cat2->y + 64)
					return (1);
			}
			}
		}
	return (0);
}

int	check_enemy_bump_each(t_game *game, t_enemy *cat)
{
	t_enemy **arr;
	arr = game->cat_arr;
	int k = 0;
	
	while(arr[k])
	{
		if(cat != arr[k])
		{
			if(cat->direction == 0 && cat->y > arr[k]->y)
				return(check_enemy_bump_up(cat, arr[k]));
			if(cat->direction == 2 && cat->y < arr[k]->y)
				return(check_enemy_bump_down(cat, arr[k]));
			if(cat->direction == 1 && cat->x  > arr[k]->x)
				return(check_enemy_bump_left(cat, arr[k]));
			if(cat->direction == 3 && cat->x  < arr[k]->x)
				return(check_enemy_bump_right(cat, arr[k]));
		}
		k++;
	}
	return (0);
}	

int	check_direction_for_wall(t_enemy *cat, char **map)
{
	if (cat->direction == 3)
	{
		if (is_obstacle(map[cat->y / 64][((cat->x + cat->speed) / 64) + 1]))
			return (1);
	}
	else if (cat->direction == 1)
	{
		if (is_obstacle(map[cat->y / 64][((cat->x - cat->speed )/ 64)]))
			return (1);
	}
	else if (cat->direction == 0)
	{
		if (is_obstacle(map[((cat->y - cat->speed) / 64)][cat->x / 64]))
			return (1);
	}
	else if (cat->direction == 2)
	{
		if (is_obstacle(map[((cat->y + cat->speed) / 64 + 1)][(cat->x / 64)]))
			return (1);
	}
	return (0);
}
void	set_enemy_direction_help(t_enemy *cat)
{
	if(cat->x % 64 == 0 && cat->y % 64 == 0)
	{
		cat->direction = rand_range_exclude(0, 3, cat->direction, cat->direction);
	}
	else if(cat->y % 64 == 0)
	{
		cat->direction = rand_max_exclude(3, cat->direction, 0, 2);
	}
	else if(cat->x % 64 == 0)
	{
		cat->direction = rand_max_exclude(3, cat->direction, 1, 3);
	}
	else if(cat->direction == 2 || cat->direction == 3)
	{
		cat->direction -= 2;
	}
	else
		cat->direction += 2;
}
void	set_enemy_direction(t_enemy *cat, t_game *game, char **map, int recursion)
{
	if(recursion > 20)
	{
		cat->freeze = 1;
		return ;
	}
	if (check_direction_for_wall(cat, map))
		set_enemy_direction_help(cat);
	if (check_direction_for_wall(cat, map))
	{
		recursion++;
		set_enemy_direction(cat, game, map, recursion);
	}
	if (cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
	else
		cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
}
void	set_enemy_direction2(t_enemy *cat, t_game *game, char **map)
{
	if (cat->x % 64 == 0 && cat->y % 64 == 0)
		cat->direction = rand_range(0, 3);
	else if (cat->x % 64 != 0)
		cat->direction = rand_max_exclude(3, 0, 2, 6);
	else if (cat->y % 64 != 0)
			cat->direction = rand_max_exclude(3, 1, 3, 6);
	else
		cat->freeze = 1;
	if(cat->freeze == 1)
		return ;
	if (check_direction_for_wall(cat, map))
		set_enemy_direction2(cat, game, map);
}

void	animate_cat(t_enemy *cat, t_game *game)
{
	int w = 64;
	int h = 64;
	char *path;
	path = ft_calloc(22, 1);
	snprintf(path, 22, "./enemy_img/%d/%d/%d.xpm", cat->color, cat->direction, cat->frame);
	free(cat->cur);
	cat->cur = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	free(path);
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
void check_surrounded_by_walls(t_enemy *cat, char **map, int *n)
{
	if (is_obstacle(map[cat->y / 64][((cat->x + cat->speed) / 64) + 1]))
		(*n)++;
	if (is_obstacle(map[cat->y / 64][((cat->x - cat->speed)/ 64)]))
		(*n)++;
	if (is_obstacle(map[((cat->y - cat->speed) / 64)][cat->x / 64]))
		(*n)++;
	if (is_obstacle(map[((cat->y + cat->speed) / 64 + 1)][(cat->x / 64)]))
		(*n)++;
	printf("n value WALLS color %d, going in direction %d, coordinates %d-%d : %d\n", cat->color, cat->direction, cat->x, cat->y, *n);
}
void	check_surrounded(t_enemy *cat, char **map)
{
	int n = 0;
	check_surrounded_by_walls(cat, map, &n);
	printf("n value for cat color %d, going in direction %d, coordinates %d-%d : %d\n", cat->color, cat->direction, cat->x, cat->y, n);
	if(n >= 4)
		cat->freeze = 1;
	else
		cat->freeze = 0;
}
void	move_enemy(t_enemy *cat, t_game *game)
{
	char *path;
	int w = 64;
	int h = 64;
	check_surrounded(cat, game->map->map_arr);
	if(cat->freeze == 1)
		return ;
	set_enemy_direction(cat, game, game->map->map_arr, 10);
	if(cat->freeze == 1)
		return ;
	animate_cat(cat, game);
	change_pos(cat);
	cat->counter += cat->speed;
	cat->frame_counter += cat->speed;
	if(cat->frame_counter > 15)
	{
		path = ft_calloc(22, 1);
		cat->frame_counter = 0;
		cat->frame++;
		if(cat->frame > 3)
			cat->frame = 0;
		path = ft_calloc(22, 1);
		snprintf(path, 22, "./enemy_img/%d/%d/%d.xpm", cat->color, cat->direction, cat->frame);
		free(cat->cur);
		cat->cur = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
		free(path);
	}
	check_surrounded(cat, game->map->map_arr);
	if(cat->freeze == 1)
		return ;
	if ((cat->counter == cat->p_len || cat->counter > 2000) && (cat->x % 64 == 0 || cat->y % 64 == 0))
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
