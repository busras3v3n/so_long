/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:09:26 by busseven          #+#    #+#             */
/*   Updated: 2024/12/23 12:46:28 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	**ft_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
void	free_map(t_map	*map)
{
	ft_freeall(map->map_arr);
	ft_freeall(map->map_arr_copy);
	exit(1);
}

void	check_map_validity(t_map	*map)
{
	char	**map_cp;
	int		wall;

	map_cp = map->map_arr_copy;

	check_rectangular(map_cp, map);
	wall = check_walls(map_cp);
	if(!wall)
	{
		write(1, "the map isn't surrounded by walls.", 34);
		free_map_exit(map);
	}
}

char	*make_map_string(char	*path)
{
	char	*line;
	char	*ret;
	int		fd;

	fd = open(path, O_RDWR, 0777);

	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		ret = ft_join(ret, line);
		free(line);
	}
	close(fd);
	return(ret);
}

void	handle_map(char	*path, t_game	*game)
{
	t_map	*map;
	char	*map_string;
	
	map_string = make_map_string(path);
	map->map_arr = ft_split(map_string, '\n');
	map->map_arr_copy = ft_split(map_string, '\n');
	free(map_string);
	check_map_validity(map);
	game->map = map;
}