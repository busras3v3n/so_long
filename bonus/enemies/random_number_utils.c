/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:28:33 by busseven          #+#    #+#             */
/*   Updated: 2025/03/04 16:39:27 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	rand_range(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

int	rand_range_exclude(int min, int max, int exclude, int exclude2)
{
	int	rd;

	rd = (rand() % (max - min + 1)) + min;
	if (rd == exclude || rd == exclude2)
	{
		return (rand_range_exclude(min, max, exclude, exclude2));
	}
	return (rd);
}

int	rand_max_exclude(int max, int exclude, int exclude2, int exclude3)
{
	int	rd;

	rd = (rand() % (max + 1));
	if (rd == exclude || rd == exclude2 || rd == exclude3)
	{
		return (rand_max_exclude(max, exclude, exclude2, exclude3));
	}
	return (rd);
}

int	rand_range_divides_x(int min, int max, int x)
{
	int	rd;

	rd = rand_range(min, max);
	if (x % rd != 0)
	{
		return (rand_range_divides_x(min, max, x));
	}
	return (rd);
}
