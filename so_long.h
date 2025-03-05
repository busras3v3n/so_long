/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 11:54:00 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map_arr;
	char	**map_arr_copy;
	char	*map_str;
	int		carrot_cnt;
	int		start_cnt;
	int		end_cnt;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		exit_xs;
	int		exit_ys;
	int		carrot_check;
	int		end_check;
	int		error;
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
	int		win_condition;
	int		delay;
}	t_game;

void	check_xpm(void);
void	map_file_open_check(char *path);
void	ber_extension_check(char *path);
void	close_fds_arr(int	*fds);
void	open_xpm_and_txt_files(int *fds);
void	find_player_start(t_map *map, char **map_cp);
void	find_path(int x, int y, char **map_cp, t_map *map);
void	check_valid_path(t_map	*map);
void	handle_map(char	*path, t_map *map);
char	*make_map_string(char	*path);
void	check_map_validity(t_map	*map);
void	set_map_dimensions(char **map_arr, t_map *map);
void	char_count_error(t_map *map);
void	free_map_exit(t_map	*map);
void	count_chars(char **map_arr, t_map *map);
int		is_valid_char(char c);
int		has_valid_chars(char **map_arr);
int		is_rectangular(char **map_arr, t_map	*map);
int		check_walls(char **map_arr, t_map *map);
void	move_player(t_game *game, int keycode);
void	place_tile_player_left(t_game *game);
void	move_count(char	**map, t_game *game, int keycode);
void	you_win(t_game *game);
void	handle_window(t_map	*map);
int		key_hook(int keycode, t_game *game);
void	reset_game(t_game *game);
void	check_if_won(t_game *game);
void	free_everything_exit(t_game	*game);
char	**ft_free_td(char **arr);
void	destroy_img(t_game	*game);
void	free_map_char(t_game	*game);
void	free_everything_exit(t_game	*game);
void	draw_end_screen(t_game *game, int res);
void	xpm_to_ptr(t_game *game);
void	draw_map(t_game *game);
void	put_img(char **map, t_game *game, int x, int y);
int		is_obstacle(char c);

#endif






