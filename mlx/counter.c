/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:30 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 10:40:23 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_digit_arr(void	**arr)
{
	arr = ft_calloc(10, sizeof(void *));
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
	arr[0] = mlx_xpm_file_to_image();
}
void	display_moves(void	*win, int	n)
{
	char *num = ft_itoa(n);
}