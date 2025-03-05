/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:47 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 12:18:44 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_fds_arr(int	*fds)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		close(fds[i]);
		i++;
	}
}

void	ber_extension_check(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
	{
		ft_printf("Error\nBad file extension\n");
		exit(1);
	}
	if (path[len - 1] != 'r' || path[len - 2] != 'e')
	{
		ft_printf("Error\nBad file extension\n");
		exit(1);
	}
	else if (path[len - 3] != 'b' || path[len - 4] != '.')
	{
		ft_printf("Error\nBad file extension\n");
		exit(1);
	}
}

void	map_file_open_check(char *path)
{
	int	fd;

	fd = open(path, O_RDWR, 0777);
	if (fd <= 0)
	{
		ft_printf("Error\nInvalid map file\n");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	check_xpm(void)
{
	int	*file_descriptors;
	int	i;

	file_descriptors = ft_calloc(10, sizeof(int));
	open_xpm_and_txt_files(file_descriptors);
	i = 0;
	while(i < 10)
	{
		if(file_descriptors[i] < 0)
		{
			close_fds_arr(file_descriptors);
			free(file_descriptors);
			ft_printf("Error\nmissing xpm file\n");
			exit(1);
		}
		i++;
	}
	close_fds_arr(file_descriptors);
	free(file_descriptors);
}
