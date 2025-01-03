/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:15:39 by busseven          #+#    #+#             */
/*   Updated: 2025/01/03 13:24:06 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(char **map, t_game *game, int x, int y)
{
	void	*m;
	void	*w;

	m = game->mlx;
	w = game->window;
	if (map[y][x] == '1')
		mlx_put_image_to_window(m, w, game->map->wall, x * 64, y * 64);
	else if (map[y][x] == '0' || map[y][x] == 'X')
		mlx_put_image_to_window(m, w, game->map->grass, x * 64, y * 64);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window(m, w, game->map->carrot, x * 64, y * 64);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(m, w, game->map->house, x * 64, y * 64);
	else if (map[y][x] == 'P')
	{
		mlx_put_image_to_window(m, w, game->cha->cur, x * 64, y * 64);
		game->cha->x = x;
		game->cha->y = y;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	if (game->win_condition == 1)
		return ;
	map = game->map->map_arr;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			put_img(map, game, x, y);
			x++;
		}
		y++;
	}
	ft_printf("\r%d", game->cha->moves);
	display_moves(game, game->cha->moves);
}

void	xpm_to_ptr(t_game *game)
{
	int		h;
	int		w;
	t_map	*map;
	t_cha	*cha;

	h = 64;
	w = 64;
	cha = game->cha;
	map = game->map;
	map->grass = mlx_xpm_file_to_image(game->mlx, "./img/pg.xpm", &w, &h);
	map->house = mlx_xpm_file_to_image(game->mlx, "./img/exi.xpm", &w, &h);
	map->wall = mlx_xpm_file_to_image(game->mlx, "./img/bw.xpm", &w, &h);
	map->carrot = mlx_xpm_file_to_image(game->mlx, "./img/car.xpm", &w, &h);
	cha->up = mlx_xpm_file_to_image(game->mlx, "./img/ru.xpm", &w, &h);
	cha->down = mlx_xpm_file_to_image(game->mlx, "./img/rs.xpm", &w, &h);
	cha->left = mlx_xpm_file_to_image(game->mlx, "./img/rl.xpm", &w, &h);
	cha->right = mlx_xpm_file_to_image(game->mlx, "./img/rr.xpm", &w, &h);
	cha->cur = game->cha->down;
}

void	draw_end_screen(t_game *game, int res)
{
	void	*win;
	void	*mlx;
	int		h;
	int		w;

	win = game->window;
	mlx = game->mlx;
	h = 192;
	w = 192;
	mlx_clear_window(game->mlx, game->window);
	if (res == 1)
	{
		game->map->exit_x = -1;
		game->map->exit_y = -1;
		game->win_img = mlx_xpm_file_to_image(mlx, "./img/ywr.xpm", &w, &h);
		mlx_put_image_to_window(mlx, win, game->win_img, 0, 0);
	}
}
