/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:51:50 by lzari             #+#    #+#             */
/*   Updated: 2024/11/17 17:35:09 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	ft_putchar(n % 10 + 48);
	count++;
	return (count);
}
