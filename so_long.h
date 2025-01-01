/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2025/01/01 11:16:53 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include "./ft_printf/libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_map
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
}	t_cha;

typedef	struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_cha	*cha;
}	t_game;

void	check_img();
void	check_img2();
void	check_img3();
void	extension_check(char *path);
void	open_check(char *path);
void	check_xpm();
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


#endif