/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:30 by busseven          #+#    #+#             */
/*   Updated: 2025/01/17 17:46:16 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_digit_arr(void	**arr, t_game *game)
{
	int	h;
	int	w;

	h = 64;
	w = 44;
	arr[0] = mlx_xpm_file_to_image(game->mlx, "./counter_img/z.xpm", &w, &h);
	arr[1] = mlx_xpm_file_to_image(game->mlx, "./counter_img/o.xpm", &w, &h);
	arr[2] = mlx_xpm_file_to_image(game->mlx, "./counter_img/t.xpm", &w, &h);
	arr[3] = mlx_xpm_file_to_image(game->mlx, "./counter_img/th.xpm", &w, &h);
	arr[4] = mlx_xpm_file_to_image(game->mlx, "./counter_img/fo.xpm", &w, &h);
	arr[5] = mlx_xpm_file_to_image(game->mlx, "./counter_img/fi.xpm", &w, &h);
	arr[6] = mlx_xpm_file_to_image(game->mlx, "./counter_img/si.xpm", &w, &h);
	arr[7] = mlx_xpm_file_to_image(game->mlx, "./counter_img/se.xpm", &w, &h);
	arr[8] = mlx_xpm_file_to_image(game->mlx, "./counter_img/ei.xpm", &w, &h);
	arr[9] = mlx_xpm_file_to_image(game->mlx, "./counter_img/ni.xpm", &w, &h);
}

void	display_moves(t_game *game, int n)
{
	char	*num;
	size_t	i;
	void	**arr;
	void	*win;

	i = 0;
	num = ft_itoa(n);
	arr = game->digit_img;
	win = game->window;
	while (i < ft_strlen(num))
	{
		mlx_put_image_to_window(game->mlx, win, arr[num[i] - 48], i * 64, 0);
		i++;
	}
	free(num);
}

void	draw_map_topy(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	if (game->win_condition == 1)
		return ;
	map = game->map->map_arr;
	y = 0;
	while (map[y] && y == 0)
	{
		x = 0;
		while (map[y][x])
		{
			put_img(map, game, x, y);
			x++;
		}
		y++;
	}
	display_moves(game, game->cha->moves);
}
