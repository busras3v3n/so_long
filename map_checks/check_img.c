/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:03:26 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 10:42:45 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_xpm_and_txt_files(int *fds)
{
	fds[0] = open("./img/bw.xpm", O_RDONLY);
	fds[1] = open("./img/car.xpm", O_RDONLY);
	fds[2] = open("./img/exi.xpm", O_RDONLY);
	fds[3] = open("./img/ywr.xpm", O_RDONLY);
	fds[4] = open("./img/pg.xpm", O_RDONLY);
	fds[5] = open("./img/rl.xpm", O_RDONLY);
	fds[6] = open("./img/rr.xpm", O_RDONLY);
	fds[7] = open("./img/rs.xpm", O_RDONLY);
	fds[8] = open("./img/ru.xpm", O_RDONLY);
	fds[9] = open("./txt/youwon.txt", O_RDONLY);
}
