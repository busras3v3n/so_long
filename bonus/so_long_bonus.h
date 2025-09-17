/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 17:50:51 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

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
	void	*wall;
	void	*grass;
	void	*house;
	void	*carrot;
	void	*gold_carrot;
	int		enemy_cnt;
}	t_map;

typedef struct s_cha
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*gup;
	void	*gdown;
	void	*gleft;
	void	*gright;
	void	*cur;
	int		moves;
	int		carrots;
	int		x;
	int		y;
	int		killer;
}	t_cha;

typedef struct s_enemy
{
	int		direction;
	int		p_len;
	int		counter;
	int		speed;
	void	*cur;
	int		color;
	int		frame_counter;
	int		frame;
	int		x;
	int		y;
	int		freeze;
	int		priority;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_cha	*cha;
	void	*win_img;
	void	**digit_img;
	int		win_condition;
	int		delay;
	t_enemy	**cat_arr;
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
void	draw_map_topy(t_game *game);
void	display_moves(t_game *game, int n);
void	make_digit_arr(void	**arr, t_game *game);
int		rand_range_divides_x(int min, int max, int x);
int		rand_max_exclude(int max, int exclude, int exclude2, int exclude3);
int		rand_range_exclude(int min, int max, int exclude, int exclude2);
int		rand_range(int min, int max);
void	check_lose(t_game *game);
void	move_all_enemies(t_game *game);
void	move_enemy(t_enemy *cat, t_game *game);
void	change_pos(t_enemy *cat);
void	enemy_init(t_game *game);
void	set_enemy_direction(t_enemy *cat, t_game *game, char **map);
void	change_direction(t_enemy *cat);
void	set_enemy_prop(t_enemy *cat, t_game *game);
void	check_begin_pos(t_enemy *cat, char **map, int k);
void	sort_enemies_by_priority(t_enemy **arr);
void	animate_cat(t_enemy *cat, t_game *game);
void	check_surrounded(t_enemy *cat, t_game *game);
int		check_for_wall(t_enemy *cat, char **map);
int		check_bump_each(t_enemy *cat, t_enemy **arr);
int		check_bump_two(t_enemy *cat, t_enemy *cat2);
int		is_obstacle(char c);
void	open_bonus_enemy_assets_whitecat(int *fds);
void	open_bonus_enemy_assets_greycat(int *fds);
void	open_bonus_enemy_assets_gingercat(int *fds);
void	open_bonus_enemy_assets_browncat(int *fds);
void	open_bonus_number_assets(int *fds);

#endif