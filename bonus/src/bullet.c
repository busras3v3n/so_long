/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:15:50 by busseven          #+#    #+#             */
/*   Updated: 2025/09/18 11:51:40 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_img_bullet(t_game *game)
{
	void	*m;
	void	*w;

	m = game->mlx;
	w = game->window;
	if(game->cha->bullet_shot)
		mlx_put_image_to_window(m, w, game->cha->bullet, game->cha->bullet_x, game->cha->bullet_y);
}

int	check_for_wall_bullet(t_game *game, char **map)
{
	if (game->cha->bullet_dir == 3)
	{
		if (is_obstacle(map[game->cha->bullet_y / 64][((game->cha->bullet_x + 10) / 64) + 1]))
			return (1);
	}
	else if (game->cha->bullet_dir == 1)
	{
		if (is_obstacle(map[game->cha->bullet_y / 64][((game->cha->bullet_x - 10) / 64)]))
			return (1);
	}
	else if (game->cha->bullet_dir == 2)
	{
		if (is_obstacle(map[((game->cha->bullet_y - 10) / 64)][game->cha->bullet_x / 64]))
			return (1);
	}
	else if (game->cha->bullet_dir == 4)
	{
		if (is_obstacle(map[((game->cha->bullet_y + 10) / 64 + 1)][(game->cha->bullet_x / 64)]))
			return (1);
	}
	return (0);
}

void	move_bullet(t_game *game)
{
	if(check_for_wall_bullet(game, game->map->map_arr))
	{
		game->cha->bullet_shot = 0;
		game->cha->killer = 0;
		if (game->cha->cur == game->cha->gright)
			game->cha->cur = game->cha->right;
		if (game->cha->cur == game->cha->gleft)
			game->cha->cur = game->cha->left;
		if (game->cha->cur == game->cha->gdown)
			game->cha->cur = game->cha->down;	
		if (game->cha->cur == game->cha->gup)
			game->cha->cur = game->cha->up;	
	}
	if(game->cha->bullet_shot == 1)
	{
		if(game->cha->bullet_dir == 1)
			game->cha->bullet_x-=10;
		if(game->cha->bullet_dir == 2)
			game->cha->bullet_y-=10;
		if(game->cha->bullet_dir == 3)
			game->cha->bullet_x+=10;
		if(game->cha->bullet_dir == 4)
			game->cha->bullet_y+=10;
	}
}