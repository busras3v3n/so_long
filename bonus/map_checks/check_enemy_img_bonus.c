/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_img_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:05:15 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 12:51:13 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long_bonus.h"

void	open_bonus_enemy_assets_whitecat(int *fds)
{
	fds[21] = open("./enemy_img/0/0/0.xpm", O_RDONLY);
	fds[22] = open("./enemy_img/0/0/1.xpm", O_RDONLY);
	fds[23] = open("./enemy_img/0/0/2.xpm", O_RDONLY);
	fds[24] = open("./enemy_img/0/0/3.xpm", O_RDONLY);
	fds[25] = open("./enemy_img/0/1/0.xpm", O_RDONLY);
	fds[26] = open("./enemy_img/0/1/1.xpm", O_RDONLY);
	fds[27] = open("./enemy_img/0/1/2.xpm", O_RDONLY);
	fds[28] = open("./enemy_img/0/1/3.xpm", O_RDONLY);
	fds[29] = open("./enemy_img/0/2/0.xpm", O_RDONLY);
	fds[30] = open("./enemy_img/0/2/1.xpm", O_RDONLY);
	fds[31] = open("./enemy_img/0/2/2.xpm", O_RDONLY);
	fds[32] = open("./enemy_img/0/2/3.xpm", O_RDONLY);
	fds[33] = open("./enemy_img/0/3/0.xpm", O_RDONLY);
	fds[34] = open("./enemy_img/0/3/1.xpm", O_RDONLY);
	fds[35] = open("./enemy_img/0/3/2.xpm", O_RDONLY);
	fds[36] = open("./enemy_img/0/3/3.xpm", O_RDONLY);
}

void	open_bonus_enemy_assets_greycat(int *fds)
{
	fds[37] = open("./enemy_img/1/0/0.xpm", O_RDONLY);
	fds[38] = open("./enemy_img/1/0/1.xpm", O_RDONLY);
	fds[39] = open("./enemy_img/1/0/2.xpm", O_RDONLY);
	fds[40] = open("./enemy_img/1/0/3.xpm", O_RDONLY);
	fds[41] = open("./enemy_img/1/1/0.xpm", O_RDONLY);
	fds[42] = open("./enemy_img/1/1/1.xpm", O_RDONLY);
	fds[43] = open("./enemy_img/1/1/2.xpm", O_RDONLY);
	fds[44] = open("./enemy_img/1/1/3.xpm", O_RDONLY);
	fds[45] = open("./enemy_img/1/2/0.xpm", O_RDONLY);
	fds[46] = open("./enemy_img/1/2/1.xpm", O_RDONLY);
	fds[47] = open("./enemy_img/1/2/2.xpm", O_RDONLY);
	fds[48] = open("./enemy_img/1/2/3.xpm", O_RDONLY);
	fds[49] = open("./enemy_img/1/3/0.xpm", O_RDONLY);
	fds[50] = open("./enemy_img/1/3/1.xpm", O_RDONLY);
	fds[51] = open("./enemy_img/1/3/2.xpm", O_RDONLY);
	fds[52] = open("./enemy_img/1/3/3.xpm", O_RDONLY);
}

void	open_bonus_enemy_assets_gingercat(int *fds)
{
	fds[53] = open("./enemy_img/2/0/0.xpm", O_RDONLY);
	fds[54] = open("./enemy_img/2/0/1.xpm", O_RDONLY);
	fds[55] = open("./enemy_img/2/0/2.xpm", O_RDONLY);
	fds[56] = open("./enemy_img/2/0/3.xpm", O_RDONLY);
	fds[57] = open("./enemy_img/2/1/0.xpm", O_RDONLY);
	fds[58] = open("./enemy_img/2/1/1.xpm", O_RDONLY);
	fds[59] = open("./enemy_img/2/1/2.xpm", O_RDONLY);
	fds[60] = open("./enemy_img/2/1/3.xpm", O_RDONLY);
	fds[61] = open("./enemy_img/2/2/0.xpm", O_RDONLY);
	fds[62] = open("./enemy_img/2/2/1.xpm", O_RDONLY);
	fds[63] = open("./enemy_img/2/2/2.xpm", O_RDONLY);
	fds[64] = open("./enemy_img/2/2/3.xpm", O_RDONLY);
	fds[65] = open("./enemy_img/2/3/0.xpm", O_RDONLY);
	fds[66] = open("./enemy_img/2/3/1.xpm", O_RDONLY);
	fds[67] = open("./enemy_img/2/3/2.xpm", O_RDONLY);
	fds[68] = open("./enemy_img/2/3/3.xpm", O_RDONLY);
}

void	open_bonus_enemy_assets_browncat(int *fds)
{
	fds[69] = open("./enemy_img/3/0/0.xpm", O_RDONLY);
	fds[70] = open("./enemy_img/3/0/1.xpm", O_RDONLY);
	fds[71] = open("./enemy_img/3/0/2.xpm", O_RDONLY);
	fds[72] = open("./enemy_img/3/0/3.xpm", O_RDONLY);
	fds[73] = open("./enemy_img/3/1/0.xpm", O_RDONLY);
	fds[74] = open("./enemy_img/3/1/1.xpm", O_RDONLY);
	fds[75] = open("./enemy_img/3/1/2.xpm", O_RDONLY);
	fds[76] = open("./enemy_img/3/1/3.xpm", O_RDONLY);
	fds[77] = open("./enemy_img/3/2/0.xpm", O_RDONLY);
	fds[78] = open("./enemy_img/3/2/1.xpm", O_RDONLY);
	fds[79] = open("./enemy_img/3/2/2.xpm", O_RDONLY);
	fds[80] = open("./enemy_img/3/2/3.xpm", O_RDONLY);
	fds[81] = open("./enemy_img/3/3/0.xpm", O_RDONLY);
	fds[82] = open("./enemy_img/3/3/1.xpm", O_RDONLY);
	fds[83] = open("./enemy_img/3/3/2.xpm", O_RDONLY);
	fds[84] = open("./enemy_img/3/3/3.xpm", O_RDONLY);
}
