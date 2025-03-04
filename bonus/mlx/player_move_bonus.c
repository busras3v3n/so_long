/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:14:07 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 16:41:11 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	you_win(t_game *game)
{
	char	*msg;
	char	**msg2;
	int		y;
	int		x;

	y = 0;
	game->win_condition = 1;
	ft_printf("\n");
	msg = make_map_string("./txt/youwon.txt");
	msg2 = ft_split(msg, '\n');
	while (msg2[y])
	{
		x = 0;
		while (msg2[y][x])
		{
			ft_printf("%c", msg2[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("you moved %d times\nPress 'R' to replay", game->cha->moves);
	free(msg);
	ft_free_td(msg2);
	draw_end_screen(game, 1);
}

void	move_count(char	**map, t_game *game, int keycode)
{
	if (keycode == 119)
	{
		if (map[game->cha->y - 1][game->cha->x] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->up;
	}
	else if (keycode == 97)
	{
		if (map[game->cha->y][game->cha->x - 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->left;
	}
	else if (keycode == 115)
	{
		if (map[game->cha->y + 1][game->cha->x] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->down;
	}
	else if (keycode == 100)
	{
		if (map[game->cha->y][game->cha->x + 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->right;
	}
}

void	move_player_help(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map_arr;
	x = game->cha->x;
	y = game->cha->y;
	if ((y == game->map->exit_y) && (x == game->map->exit_x))
		map[game->cha->y][game->cha->x] = 'E';
	else
		map[game->cha->y][game->cha->x] = '0';
}

void	move_player(t_game *game, int keycode)
{
	char	**map;

	map = game->map->map_arr;
	move_player_help(game);
	move_count(map, game, keycode);
	if (keycode == 119 && map[game->cha->y - 1][game->cha->x] != '1')
		game->cha->y--;
	else if (keycode == 97 && map[game->cha->y][game->cha->x - 1] != '1')
		game->cha->x--;
	else if (keycode == 115 && map[game->cha->y + 1][game->cha->x] != '1')
		game->cha->y++;
	else if (keycode == 100 && map[game->cha->y][game->cha->x + 1] != '1')
		game->cha->x++;
	if (map[game->cha->y][game->cha->x] == 'C')
		game->cha->carrots++;
	map[game->cha->y][game->cha->x] = 'P';
	draw_map(game);
	if (game->cha->y == game->map->exit_y && game->cha->x == game->map->exit_x)
	{
		if (game->map->carrot_cnt == game->cha->carrots)
			you_win(game);
	}
	if (game->win_condition == 0 && game->map->enemy_cnt != 0)
		check_lose(game);
	draw_map_topy(game);
}
