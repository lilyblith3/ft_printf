/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:58:23 by lzari             #+#    #+#             */
/*   Updated: 2024/11/18 13:22:54 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chr(unsigned long ptr)
{
	int		printed_chars;
	char	*hex;

	printed_chars = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		printed_chars += ft_chr(ptr / 16);
	printed_chars += ft_putchar(hex[ptr % 16]);
	return (printed_chars);
}

int	ft_print_p(unsigned long ptr)
{
	int	printed_chars;

	printed_chars = 0;
	if (!ptr)
		return (write(1, "0x0", 3));
	printed_chars += write(1, "0x", 2);
	printed_chars += ft_chr(ptr);
	return (printed_chars);
}
