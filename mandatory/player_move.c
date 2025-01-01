/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:14:07 by busseven          #+#    #+#             */
/*   Updated: 2025/01/01 17:28:23 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	you_win(t_game *game)
{
	char	*msg;

	msg = make_map_string("./youwon.txt");
	ft_printf("\n%s\nYou moved %d times!\n", msg, game->cha->moves);
	free(msg);
}

void	move_count(char	**map, t_game *game, int keycode)
{
	if(keycode == 119)
	{
		if(map[game->cha->y][game->cha->x - 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->up;
	}
	else if(keycode == 97)
	{
		if(map[game->cha->y][game->cha->x - 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->left;
	}
	else if(keycode == 115)
	{
		if(map[game->cha->y][game->cha->x - 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->down;
	}
	else if(keycode == 100)
	{
		if(map[game->cha->y][game->cha->x - 1] != '1')
			game->cha->moves++;
		game->cha->cur = game->cha->right;
	}
}
void	move_player(t_game *game, int keycode)
{
	char **map;

	map = game->map->map_arr;
	if(map[game->cha->y][game->cha->x] != 'E')
		map[game->cha->y][game->cha->x] = '0';
	move_count(map, game, keycode);
	if(keycode == 119 && map[game->cha->y - 1][game->cha->x] != '1')
		game->cha->y--;
	else if(keycode == 97 && map[game->cha->y][game->cha->x - 1] != '1')
		game->cha->x--;
	else if(keycode == 115 && map[game->cha->y + 1][game->cha->x - 1] != '1')
		game->cha->y++;
	else if(keycode == 100 && map[game->cha->y][game->cha->x + 1] != '1')
		game->cha->x++;
	if(map[game->cha->y][game->cha->x] == 'C')
		game->cha->carrots++;
	if(map[game->cha->y][game->cha->x] != 'E')
		map[game->cha->y][game->cha->x] = 'P';
	draw_map(game);
	if(map[game->cha->y][game->cha->x] == 'E')
	{
		if(game->map->carrot_cnt == game->cha->carrots)
			you_win(game);
	}
}
