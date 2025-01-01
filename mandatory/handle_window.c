/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2025/01/01 18:04:51 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_img(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->map->wall);
	mlx_destroy_image(game->mlx, game->map->house);
	mlx_destroy_image(game->mlx, game->map->grass);
	mlx_destroy_image(game->mlx, game->map->carrot);
	mlx_destroy_image(game->mlx, game->cha->up);
	mlx_destroy_image(game->mlx, game->cha->down);
	mlx_destroy_image(game->mlx, game->cha->left);
	mlx_destroy_image(game->mlx, game->cha->right);
}
void	free_everything_exit(t_game	*game)
{
	ft_freeall(game->map->map_arr);
	destroy_img(game);
	free(game->map);
	free(game->cha);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit (0);
}

int	close_window(t_game	*game)
{
	free_everything_exit(game);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_everything_exit(game);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		move_player(game, keycode);
	}
	return (0);
}

void	handle_window(t_map	*map)
{
	t_game	*game;
	t_cha	*cha;
	int		w;
	int		h;

	w = map->width;
	h = map->height;
	game = ft_calloc(1, sizeof(t_game));
	cha = ft_calloc(1, sizeof(t_cha));
	game->cha = cha;
	game->map = map;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (w * 64), (h * 64), "so_long");
	xpm_to_ptr(game);
	draw_map(game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}
