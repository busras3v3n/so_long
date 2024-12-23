/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:51:02 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 12:42:43 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H


#include "./minilibx-linux/mlx.h"
#include "./Libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>

typedef	s_map
{
	char	**map_arr;
	char	**map_arr_copy;
	int		carrot_cnt;
	int		start_cnt;
	int		end_cnt;
	int		width;
	int		height;
}	t_map;

typedef	s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
}	t_game;

void	handle_map(char	*path, t_game	*game);
void	check_rectangular(char **map_arr, t_map	*map);
int		check_walls(char	**map_arr);
void	free_map(t_map	*map);


#endif