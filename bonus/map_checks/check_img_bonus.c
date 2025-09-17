/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:03:26 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 17:57:13 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	fds[85] = open("./img/gru.xpm", O_RDONLY);
	fds[86] = open("./img/grr.xpm", O_RDONLY);
	fds[87] = open("./img/grd.xpm", O_RDONLY);
	fds[88] = open("./img/grl.xpm", O_RDONLY);
	fds[89] = open("./img/gcar.xpm", O_RDONLY);
}

void	open_bonus_number_assets(int *fds)
{
	fds[10] = open("./counter_img/ei.xpm", O_RDONLY);
	fds[11] = open("./counter_img/fi.xpm", O_RDONLY);
	fds[12] = open("./counter_img/fo.xpm", O_RDONLY);
	fds[13] = open("./counter_img/ni.xpm", O_RDONLY);
	fds[14] = open("./counter_img/o.xpm", O_RDONLY);
	fds[15] = open("./counter_img/se.xpm", O_RDONLY);
	fds[16] = open("./counter_img/si.xpm", O_RDONLY);
	fds[17] = open("./counter_img/t.xpm", O_RDONLY);
	fds[18] = open("./counter_img/th.xpm", O_RDONLY);
	fds[19] = open("./counter_img/z.xpm", O_RDONLY);
	fds[20] = open("./txt/youwon.txt", O_RDONLY);
}
