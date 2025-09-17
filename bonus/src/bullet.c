/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:15:50 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 19:20:59 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_img_bullet(t_game *game)
{
	void	*m;
	void	*w;

	m = game->mlx;
	w = game->window;
	if(game->cha->bullet_x && game->cha->bullet_y)
		mlx_put_image_to_window(m, w, game->cha->bullet, game->cha->bullet_x, game->cha->bullet_y);
}