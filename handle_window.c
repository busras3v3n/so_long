/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:59:05 by busseven          #+#    #+#             */
/*   Updated: 2024/12/31 17:28:22 by busseven         ###   ########.fr       */
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
	if(keycode == 27)
		free_everything_exit(game);
	return(0);
}
void	handle_window(t_map	*map)
{
	t_game	*game;
	
	game = ft_calloc(1, sizeof(t_game));
	game->map = map;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (map->width * 64), (map->height * 64), "so_long");
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->mlx);
}