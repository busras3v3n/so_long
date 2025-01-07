/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bump_each.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:47:10 by busseven          #+#    #+#             */
/*   Updated: 2025/01/07 13:05:58 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		collision_detection(t_enemy *cat1, t_enemy *cat2)
{
	if(cat1->direction == 1 || cat1->direction == 3)
	{
		if((cat1->x + cat1->speed)/64 == (cat2->x + cat2->speed)/64)
			return (1);
	}
	if(cat1->direction == 0 || cat1->direction == 2)
	{
		if((cat1->y + cat1->speed)/64 == (cat2->y + cat2->speed)/64)
			return (1);
	}
	return(0);
}
void	enemy_bump_each(t_enemy **arr)
{
	int k;
	int i;

	k = 0;
	i = 0;

	while(arr[i])
	{
		k = 0;
		while(arr[k])
		{
			if(k != i)
			{
				if(collision_detection(arr[i], arr[k]))
				{
				}
			}
			k++;
		}
		i++;
	}
}
