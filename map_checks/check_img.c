/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:03:26 by busseven          #+#    #+#             */
/*   Updated: 2025/01/02 09:43:55 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_img(void)
{
	int	fd_bw;
	int	fd_car;
	int	fd_hou;
	int	fd_ywr;

	fd_bw = open("./img/bw.xpm", O_RDONLY);
	fd_car = open("./img/car.xpm", O_RDONLY);
	fd_hou = open("./img/exi.xpm", O_RDONLY);
	fd_ywr = open("./img/ywr.xpm", O_RDONLY);
	if (fd_bw <= 0 || fd_car <= 0 || fd_hou <= 0 || fd_ywr <= 0)
	{
		write(1, "Error\nMissing xpm file\n", 23);
		close(fd_bw);
		close(fd_car);
		close(fd_hou);
		close(fd_ywr);
		exit(1);
	}
	close(fd_bw);
	close(fd_car);
	close(fd_hou);
}

void	check_img2(void)
{
	int	fd_pg;
	int	fd_rl;
	int	fd_rr;
	int	fd_rs;

	fd_pg = open("./img/pg.xpm", O_RDONLY);
	fd_rl = open("./img/rl.xpm", O_RDONLY);
	fd_rr = open("./img/rr.xpm", O_RDONLY);
	fd_rs = open("./img/rs.xpm", O_RDONLY);
	if (fd_pg <= 0 || fd_rl <= 0 || fd_rr <= 0 || fd_rs <= 0)
	{
		write(1, "Error\nMissing xpm file\n", 23);
		close(fd_pg);
		close(fd_rl);
		close(fd_rr);
		close(fd_rs);
		exit(1);
	}
	close(fd_pg);
	close(fd_rl);
	close(fd_rr);
	close(fd_rs);
}

void	check_img3(void)
{
	int	fd_ru;

	fd_ru = open("./img/ru.xpm", O_RDONLY);
	if (fd_ru <= 0)
	{
		write(1, "Error\nMissing xpm file\n", 23);
		close(fd_ru);
		exit(1);
	}
	close(fd_ru);
}
