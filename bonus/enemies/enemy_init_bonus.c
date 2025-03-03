/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:51:46 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 12:33:03 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include <stdio.h>

void	sort_enemies_by_priority(t_enemy **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		arr[i]->priority = i;
		i++;
	}
}

int	is_obstacle(char c)
{
	if (c == '1' || c == 'E')
		return (1);
	return (0);
}

void	check_begin_pos(t_enemy *cat, char **map, int k)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	k--;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'X')
			{
				if (k + 1 == 0)
				{
					(cat)->x = x * 64;
					(cat)->y = y * 64;
					return ;
				}
				k--;
			}
			x++;
		}
		y++;
	}
}

void	set_enemy_prop(t_enemy *cat, t_game *game)
{
	int		w;
	int		h;
	char	*path;

	path = ft_calloc(22, 1);
	w = 64;
	h = 64;
	cat->direction = rand_range(0, 3);
	cat->speed = rand_range_divides_x(5, 30, 64);
	if (cat->direction == 1 || cat->direction == 3)
		cat->p_len = rand_range(1, (game->map->width - 2)) * 64;
	else
		cat->p_len = rand_range(1, (game->map->height - 2)) * 64;
	cat->counter = 0;
	cat->frame_counter = 0;
	cat->frame = 0;
	cat->color = rand_range(0, 3);
	snprintf(path, 22, "./enemy_img/%d/%d/0.xpm", cat->color, cat->direction);
	cat->cur = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	cat->freeze = 0;
	sort_enemies_by_priority(game->cat_arr);
	free(path);
}

void	enemy_init(t_game *game)
{
	int	k;

	if (game->map->enemy_cnt == 0)
		return ;
	game->cat_arr = ft_calloc(game->map->enemy_cnt, sizeof(t_enemy));
	k = 0;
	while (k < game->map->enemy_cnt)
	{
		game->cat_arr[k] = ft_calloc(1, sizeof(t_enemy));
		check_begin_pos(game->cat_arr[k], game->map->map_arr, k);
		set_enemy_prop(game->cat_arr[k], game);
		k++;
	}
}
