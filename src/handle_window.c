/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 18:23:40 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_if_won(t_game *game)
{
	if (game->cha->y == game->map->exit_y && game->cha->x == game->map->exit_x)
	{
		if (game->map->carrot_cnt == game->cha->carrots)
			you_win(game);
	}
}

void	reset_game(t_game *game)
{
	game->map->exit_x = game->map->exit_xs;
	game->map->exit_y = game->map->exit_ys;
	if (game->map->map_arr)
		ft_free_td(game->map->map_arr);
	game->map->map_arr = ft_split(game->map->map_str, '\n');
	game->win_condition = 0;
	game->cha->moves = 0;
	game->cha->cur = game->cha->down;
	game->cha->carrots = 0;
	ft_printf("\n");
	draw_map(game);
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
		draw_map(game);
		check_if_won(game);
	}
	if (keycode == 114)
		reset_game(game);
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
	game->delay = 20;
	xpm_to_ptr(game);
	draw_map(game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}
