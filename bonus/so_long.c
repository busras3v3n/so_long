/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:41:43 by busseven          #+#    #+#             */
/*   Updated: 2025/01/06 21:03:05 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		srand(time(NULL));
		check_xpm();
		ber_file_check(argv[1]);
		map = ft_calloc(1, sizeof(t_map));
		handle_map(argv[1], map);
		handle_window(map);
	}
	else
		write(1, "Error\nIncorrect number of arguments\n", 36);
}
