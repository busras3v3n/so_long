/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_file_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:27:47 by busseven          #+#    #+#             */
/*   Updated: 2025/09/17 19:10:09 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	close_fds_arr(int	*fds)
{
	int	i;

	i = 0;
	while (i < 84)
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

	file_descriptors = ft_calloc(91, sizeof(int));
	open_xpm_and_txt_files(file_descriptors);
	open_bonus_number_assets(file_descriptors);
	open_bonus_enemy_assets_whitecat(file_descriptors);
	open_bonus_enemy_assets_greycat(file_descriptors);
	open_bonus_enemy_assets_gingercat(file_descriptors);
	open_bonus_enemy_assets_browncat(file_descriptors);
	i = 0;
	while (i < 90)
	{
		if (file_descriptors[i] < 0)
		{
			i = 0;
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
