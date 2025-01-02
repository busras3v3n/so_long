/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:52:19 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 10:16:49 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_free_td(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
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

void	free_wl(t_game	*game)
{
	ft_free_td(game->map->map_arr);
	destroy_img(game);
	free(game->cha);
}
void	free_everything_exit(t_game	*game)
{
	free_wl(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit (0);
}