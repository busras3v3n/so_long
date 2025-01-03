/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:23:14 by busseven          #+#    #+#             */
/*   Updated: 2025/01/03 18:52:23 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	enemy_count(t_game *game)
{
	char	**map
	int		x;
	int		y;

	y = 0;
	map = game->map->map_arr;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'X')
			{
				game->enemy_count++;
				x++;
			}
		}
		y++;
	}
}
void	set_enemy_initial_position(t_enemy *enemy, t_game *game)
{
	char	**map
	int		x;
	int		y;

	y = 0;
	map = game->map->map_arr;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == 'X')
			{
				enemy->x = x;
				enemy->y = y;
				x++;
			}
		}
		y++;
	}
}
void	set_current_animation(t_enemy *enemy)
{
	if(enemy->direction = 0)
		enemy->cur = enemy->up;
	if(enemy->direction = 1)
		enemy->cur = enemy->down;
	if(enemy->direction = 2)
		enemy->cur = enemy->left;
	if(enemy->direction = 3)
		enemy->cur = enemy->right;
}
int		rand_range(int max, int min)
{
	int	rd;
	int	ret;
	rd = rand();
	ret = (rd % (max - min + 1));
	return(ret);
}
void	set_enemy_prop(t_enemy *enemy, t_game *game)
{
	enemy->direction = rand_range(3, 0);
	if(enemy->direction == 0 || enemy->direction == 1)
		enemy->p_len = rand(game->map->width - 2, 2);
	else
		enemy->p_len = rand(game->map->height - 2, 2);
	enemy->up =  mlx_xpm_file_to_image(game->mlx, "./enemy_img/cu.xpm", &w, &h);
	enemy->down = mlx_xpm_file_to_image(game->mlx, "./enemy_img/cd.xpm", &w, &h);
	enemy->left = mlx_xpm_file_to_image(game->mlx, "./enemy_img/cl.xpm", &w, &h);
	enemy->right = mlx_xpm_file_to_image(game->mlx, "./enemy_img/cr.xpm", &w, &h);
	enemy->cur = set_current_animation(enemy);
	enemy->cur_frame = 0;
}

void	enemy_init(t_game *game)
{
	int	k;
	t_enemy **arr;
	char	**map;

	k = game->enemy_count;
	game->enemy_arr = ft_calloc(1, game->enemy_count * sizeof(t_enemy));
	arr = game->enemy_arr;
	map = game->map->map_arr;

	while(k > 0)
	{
		set_enemy_prop(arr[i], game);
		set_enemy_initial_position(arr[i], game);
		i++;
	}
}
int	handle_enemies(game)
{
	draw_enemy(game);
	move_enemy(game);
}

