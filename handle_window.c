/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2025/01/01 11:14:44 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_everything_exit(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	ft_freeall(game->map->map_arr);
	free(game->map);
	free(game);
	exit (0);
}

int	close_window(t_game	*game)
{
	free_everything_exit(game);
	return(0);
}
int	key_hook(int keycode, t_game *game)
{
	ft_printf("%d", keycode);
	if(keycode == 65307)
		free_everything_exit(game);
	return(0);
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
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map->map_arr;
	y = 0;
	x = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->map->wall, x * 64, y * 64);
			else if(map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->map->carrot, x * 64, y * 64);
			else if(map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->map->house, x * 64, y * 64);
			else if(map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->cha->up, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_background(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map->map_arr;
	y = 0;
	x = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->window, game->map->grass, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	draw_on_window(t_game *game)
{
	xpm_to_ptr(game);
	draw_background(game);
	draw_map(game);
}

void	handle_window(t_map	*map)
{
	t_game	*game;
	t_cha	*cha;
	
	game = ft_calloc(1, sizeof(t_game));
	cha = ft_calloc(1, sizeof(t_cha));
	game->cha = cha;
	game->map = map;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (map->width * 64), (map->height * 64), "so_long");
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
	draw_on_window(game);
	mlx_loop(game->mlx);
}
