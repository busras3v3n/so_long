/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:52:19 by busseven          #+#    #+#             */
/*   Updated: 2025/03/03 12:32:22 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	destroy_cats(t_enemy **arr, t_game *game)
{
	int	k;

	k = 0;
	while (arr[k])
	{
		if (arr[k]->cur)
			mlx_destroy_image(game->mlx, arr[k]->cur);
		free(arr[k]);
		k++;
	}
	free(arr);
}

void	destroy_void_arr(void **arr, t_game *game)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		if (arr[i])
			mlx_destroy_image(game, arr[i]);
		i++;
	}
	free(arr);
}

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

void	free_wl(t_game	*game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->map->wall);
	mlx_destroy_image(game->mlx, game->map->house);
	mlx_destroy_image(game->mlx, game->map->grass);
	mlx_destroy_image(game->mlx, game->map->carrot);
	mlx_destroy_image(game->mlx, game->cha->up);
	mlx_destroy_image(game->mlx, game->cha->down);
	mlx_destroy_image(game->mlx, game->cha->left);
	mlx_destroy_image(game->mlx, game->cha->right);
	while (i <= 9)
	{
		if (game->digit_img && game->digit_img[i])
			mlx_destroy_image(game->mlx, game->digit_img[i]);
		i++;
	}
	if (game->digit_img)
		free(game->digit_img);
	if (game->cat_arr)
		destroy_cats(game->cat_arr, game);
	ft_free_td(game->map->map_arr);
	free(game->map->map_str);
	free(game->map);
	free(game->cha);
}

void	free_everything_exit(t_game	*game)
{
	free_wl(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_printf("\n");
	exit (0);
}
