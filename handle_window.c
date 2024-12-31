/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2024/12/31 16:17:31 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_window(t_map	*map)
{
	t_game	*game;
	
	game = ft_calloc(1, sizeof(t_game));
	game->map = map;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (map->width * 64), (map->height * 64), "so_long");
	mlx_loop(game->mlx);
}