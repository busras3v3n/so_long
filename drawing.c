/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:15:39 by busseven          #+#    #+#             */
/*   Updated: 2025/01/01 13:36:00 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(char **map, t_game *game, int x, int y)
{
	if(map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->map->wall, x * 64, y * 64);
	else if(map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->map->grass, x * 64, y * 64);
	else if(map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->map->carrot, x * 64, y * 64);
	else if(map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->map->house, x * 64, y * 64);
	else if(map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->cha->cur, x * 64, y * 64);
			game->cha->x = x;
			game->cha->y = y;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map->map_arr;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			put_img(map, game, x, y);
			x++;
		}
		y++;
	}
	game->cha->moves_str = ft_itoa(game->cha->moves);
	write(1, "\r", 1);
	write(1, game->cha->moves_str, ft_strlen(game->cha->moves_str));
}

void	xpm_to_ptr(t_game *game)
{
	int	h;
	int	w;

	h = 64;
	w = 64;

	game->map->grass = mlx_xpm_file_to_image(game->mlx, "./img/plaingrass.xpm", &w, &h);
	game->map->house = mlx_xpm_file_to_image(game->mlx, "./img/house.xpm", &w, &h);
	game->map->wall = mlx_xpm_file_to_image(game->mlx, "./img/brickwall.xpm", &w, &h);
	game->map->carrot = mlx_xpm_file_to_image(game->mlx, "./img/carrot.xpm", &w, &h);
	game->cha->up = mlx_xpm_file_to_image(game->mlx, "./img/rabbitup.xpm", &w, &h);
	game->cha->down = mlx_xpm_file_to_image(game->mlx, "./img/rabbitstand.xpm", &w, &h);
	game->cha->left = mlx_xpm_file_to_image(game->mlx, "./img/rabbitleft.xpm", &w, &h);
	game->cha->right = mlx_xpm_file_to_image(game->mlx, "./img/rabbitright.xpm", &w, &h);
	game->cha->cur = game->cha->down;
}
void	draw_on_window(t_game *game)
{
	xpm_to_ptr(game);
	draw_map(game);
}