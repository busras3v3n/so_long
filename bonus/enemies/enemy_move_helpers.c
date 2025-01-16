/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:49:54 by busseven          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:38 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_bump_two(t_enemy *cat, t_enemy *cat2)
{
	int	dx;
	int	dy;
	int	s;
	int	d;

	dx = cat->x - cat2->x;
	dy = cat->y - cat2->y;
	s = cat->speed;
	d = cat->direction;
	if (dy > -64 && dy < 64)
	{
		if (d == 1 && cat->x - s < cat2->x + 64 && cat->x > cat2->x)
			return (1);
		else if (d == 3 && cat->x + s > cat2->x - 64 && cat->x < cat2->x)
			return (1);
	}
	else if (dx > -64 && dx < 64)
	{
		if (d == 0 && cat->y - s < cat2->y + 64 && cat->y > cat2->y)
			return (1);
		else if (d == 2 && cat->y + s > cat2->y - 64 && cat->y < cat2->y)
			return (1);
	}
	return (0);
}

int	check_bump_each(t_enemy *cat, t_enemy **arr)
{
	int	k;

	k = 0;
	while (arr[k])
	{
		if (cat != arr[k])
		{
			if (check_bump_two(cat, arr[k]))
				return (1);
		}
		k++;
	}
	return (0);
}

int	check_for_wall(t_enemy *cat, char **map)
{
	if (cat->direction == 3)
	{
		if (is_obstacle(map[cat->y / 64][((cat->x + cat->speed) / 64) + 1]))
			return (1);
	}
	else if (cat->direction == 1)
	{
		if (is_obstacle(map[cat->y / 64][((cat->x - cat->speed) / 64)]))
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

void	check_surrounded(t_enemy *cat, t_game *game)
{
	int		n;
	int		tmp;
	char	**map;
	int		k;

	map = game->map->map_arr;
	tmp = cat->direction;
	k = 0;
	n = 0;
	while (k <= 3)
	{
		cat->direction = k;
		if (check_bump_each(cat, game->cat_arr))
			n++;
		else if (check_for_wall(cat, map))
			n++;
		k++;
	}
	cat->direction = tmp;
	if (n >= 4)
		cat->freeze = 1;
	else
		cat->freeze = 0;
}

void	animate_cat(t_enemy *cat, t_game *game)
{
	int		w;
	int		h;
	int		d;
	char	*path;

	w = 64;
	h = 64;
	d = cat->direction;
	cat->frame_counter = 0;
	cat->frame++;
	if (cat->frame > 3)
		cat->frame = 0;
	path = ft_calloc(22, 1);
	snprintf(path, 22, "./enemy_img/%d/%d/%d.xpm", cat->color, d, cat->frame);
	mlx_destroy_image(game->mlx, cat->cur);
	cat->cur = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	free(path);
}
