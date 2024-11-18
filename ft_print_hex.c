/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:18:57 by lzari             #+#    #+#             */
/*   Updated: 2024/11/18 20:26:21 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_hex(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	ft_rec_hex(char c, unsigned int n)
{
	char	*hex_lower;
	char	*hex_upper;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (n > 15)
		ft_rec_hex(c, n / 16);
	if (c == 'x')
		ft_putchar(hex_lower[n % 16]);
	if (c == 'X')
		ft_putchar(hex_upper[n % 16]);
}

int	ft_print_hex(char c, unsigned int n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_rec_hex(c, n);
	return (ft_count_hex(n));
}
