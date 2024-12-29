/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2024/12/28 17:23:05 by busseven         ###   ########.fr       */
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
}	t_map;

typedef	struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
}	t_game;

void	check_img();
void	check_img2();
void	check_img3();
void	extension_check(char *path);
void	open_check(char *path);
void	check_xpm();
void	ber_file_check(char *path);
void	handle_map(char	*path);
int		check_rectangular(char **map_arr, t_map	*map);
int		check_walls(char	**map_arr);
void	free_map_exit(t_map	*map);
int		check_items(t_map	*map, int	*error_displayed);
void	error_msg(int	*error_displayed);
void	check_valid_path(t_map *map);


#endif