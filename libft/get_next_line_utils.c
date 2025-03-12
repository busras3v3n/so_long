/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:38 by busseven          #+#    #+#             */
/*   Updated: 2025/03/12 14:51:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_static_buffer(char *buffer, int i)
{
	if (i == 0)
	{
		if (buffer)
			free(buffer);
		return (1);
	}
	return (0);
}