/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2025/01/06 12:11:41 by busseven         ###   ########.fr       */
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
	int		enemy_cnt;
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

typedef struct s_enemy
{
	int		direction;
	int		p_len;
	int		counter;
	int		speed;
	void	*cur;
	int		x;
	int		y;
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
	t_enemy	**cat_arr;
	int		endian;
	int		bpp;
	int		sl;
	int 	delay;
	int		init;
	struct timeval last_time;
}	t_game;

void	check_img(void);
void	check_img2(void);
void	check_img3(void);
void	extension_check(char *path);
void	open_check(char *path);
void	check_xpm(void);
void	ber_file_check(char *path);
char	**ft_free_td(char **arr);
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
char	**ft_free_td(char **arr);
void	free_wl(t_game	*game);
void	free_everything_exit(t_game	*game);
void	draw_end_screen(t_game *game, int res);
void	display_moves(t_game *game, int	n);
void	make_digit_arr(void	**arr, t_game *game);
void	enemy_init(t_game *game);
void	move_all_enemies(t_game *game);
int		update_game(t_game *game);
void	you_win(t_game *game);
void	check_enemy_bump(t_game *game);
void	reset_game(t_game *game);
void	check_begin_pos(t_enemy *cat, char **map, int k);

#endif