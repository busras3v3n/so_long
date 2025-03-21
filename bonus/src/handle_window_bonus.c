/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 12:51:57 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	reset_game(t_game *game)
{
	int	k;

	k = 0;
	game->map->exit_x = game->map->exit_xs;
	game->map->exit_y = game->map->exit_ys;
	if (game->map->map_arr)
		ft_free_td(game->map->map_arr);
	game->map->map_arr = ft_split(game->map->map_str, '\n');
	game->win_condition = 0;
	game->cha->moves = 0;
	game->cha->cur = game->cha->down;
	game->cha->carrots = 0;
	while (k < game->map->enemy_cnt)
	{
		check_begin_pos(game->cat_arr[k], game->map->map_arr, k);
		k++;
	}
	ft_printf("\n");
	draw_map(game);
	draw_map_topy(game);
}

int	update_game(t_game *game)
{
	if (++game->delay % 5000 == 0)
	{
		move_all_enemies(game);
		draw_map(game);
		if (game->win_condition == 0)
		{
			check_lose(game);
		}
	}
	return (0);
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
		draw_map_topy(game);
		check_if_won(game);
	}
	if (keycode == 114)
	{
		reset_game(game);
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
	game->digit_img = ft_calloc(10, sizeof(void *));
	game->delay = 0;
	make_digit_arr(game->digit_img, game);
	xpm_to_ptr(game);
	enemy_init(game);
	draw_map_topy(game);
	draw_map(game);
	if (game->map->enemy_cnt != 0)
		mlx_loop_hook(game->mlx, update_game, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}
