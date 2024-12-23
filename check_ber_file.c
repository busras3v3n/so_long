/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:47 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 19:23:11 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension_check(char *path)
{
	int	len;

	len = ft_strlen(path);

	if(len < 4)
	{
		write(1, "Error\nInvalid file extension\n", 29);
		exit(1);
	}
	if(path[len - 1] != 'r' || path[len - 2] != 'e')
	{
		write(1, "Error\nInvalid file extension\n", 29);
		exit(1);
	}
	else if(path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(1, "Error\nInvalid file extension\n", 29);
		exit(1);
	}
}

void	open_check(char *path)
{
	int	fd;

	fd = open(path, O_RDWR, 0777);
	if(fd <= 0)
	{
		write(1, "Error\nFile does not exist\n", 20);
		close(fd);
		exit(1);
	}
	close(fd);
}
void	ber_file_check(char *path)
{
	extension_check(path);
	open_check(path);
}

void	check_xpm()
{
	check_img();
	check_img2();
	check_img3();
}