/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:01:23 by busseven          #+#    #+#             */
/*   Updated: 2025/03/05 11:49:13 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_ptr(unsigned long long n, int fd)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex_ptr(n / 16, fd);
		count += ft_print_hex_ptr(n % 16, fd);
	}
	else if (n < 16)
	{
		write(fd, &base[n], 1);
		count++;
	}
	return (count);
}

int	ft_print_ptr(void *p)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_print_str("0x");
	return (ft_print_hex_ptr((unsigned long long) p, 1) + 2);
}
