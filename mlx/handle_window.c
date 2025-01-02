/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 09:55:42 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



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
