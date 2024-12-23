/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:47 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 13:33:06 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension_check(char *path)
{
	int	len;

	len = ft_strlen(path);

	if(len < 4)
	{
		write(1, "invalid file extension\n", 23);
		exit(1);
	}
	if(path[len - 1] != 'r' || path[len - 2] != 'e')
	{
		write(1, "invalid file extension\n", 23);
		exit(1);
	}
	else if(path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(1, "invalid file extension\n", 23);
		exit(1);
	}
}

void	open_check(char *path)
{
	int	fd;

	fd = open(path, O_RDWR, 0777);
	if(fd <= 0)
	{
		write(1, "file does not exist\n", 20);
		close(fd);
		exit(1);
	}
	close(fd);
}