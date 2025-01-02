/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 09:46:14 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map_arr;
	char	**map_arr_copy;
	int		carrot_cnt;
	int		start_cnt;
	int		end_cnt;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		carrot_check;
	int		end_check;
	void	*wall;
	void	*grass;
	void	*house;
	void	*carrot;
}	t_map;

typedef struct s_cha
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*cur;
	int		moves;
	int		carrots;
	int		x;
	int		y;
}	t_cha;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_cha	*cha;
	void	*win_img;
}	t_game;

void	check_img(void);
void	check_img2(void);
void	check_img3(void);
void	extension_check(char *path);
void	open_check(char *path);
void	check_xpm(void);
void	ber_file_check(char *path);
char	**ft_freeall(char **arr);
void	handle_map(char	*path, t_map *map);
int		check_rectangular(char **map_arr, t_map	*map);
int		check_walls(char	**map_arr);
void	free_map_exit(t_map	*map);
int		check_items(t_map	*map, int	*error_displayed);
void	error_msg(int	*error_displayed);
void	check_valid_path(t_map *map);
void	handle_window(t_map	*map);
void	draw_on_window(t_game *game);
void	draw_map(t_game *game);
void	move_player(t_game *game, int keycode);
char	*make_map_string(char	*path);
void	destroy_img(t_game	*game);
void	xpm_to_ptr(t_game *game);

#endif