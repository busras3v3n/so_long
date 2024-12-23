/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:03:26 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 10:13:26 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img()
{
	int	fd_bw
	int	fd_car
	int	fd_fg
	int	fd_hou
	
	fd_bw = open("./img/brickwall.xpm", O_RDWR, 0777);
	fd_car = open("./img/carrot.xpm", O_RDWR, 0777)
	fd_fg = open("./img/flowergrass.xpm", O_RDWR, 0777)
	fd_hou = open("./img/house.xpm", O_RDWR, 0777)

	if(fd_bw <= 0 | fd_car <= 0 | fd_fg <= 0 | fd_hou <= 0)
	{
		write(1, "Missing xpm file\n");
		close(fd_bw);
		close(fd_car);
		close(fd_fg);
		close(fd_hou);
		exit(1);
	}
	close(fd_bw);
	close(fd_car);
	close(fd_fg);
	close(fd_hou);
}

void	check_img2()
{
	int	fd_pg
	int	fd_rl
	int	fd_rr
	int	fd_rs
	
	fd_pg = open("./img/plaingrass.xpm", O_RDWR, 0777);
	fd_rl = open("./img/rabbitleft.xpm", O_RDWR, 0777)
	fd_rr = open("./img/rabbitright.xpm", O_RDWR, 0777)
	fd_rs = open("./img/rabbitstand.xpm", O_RDWR, 0777)

	if(fd_pg <= 0 | fd_rl <= 0 | fd_rr <= 0 | fd_rs <= 0)
	{
		write(1, "Missing xpm file\n");
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

void	check_img3()
{
	int	fd_ru
	
	fd_ru = open("./img/rabbitup.xpm", O_RDWR, 0777);

	if(fd_ru <= 0)
	{
		write(1, "Missing xpm file\n");
		close(fd_ru);
		exit(1);
	}
	close(fd_ru);
}
