/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:13:46 by lzari             #+#    #+#             */
/*   Updated: 2024/11/18 13:03:22 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	argc;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(argc, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += ft_format(format[i], argc);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(argc);
	return (count);
}

int	ft_format(const char c, va_list args)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_print_p(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		print += ft_print_num(va_arg(args, int));
	else if (c == 'u')
		print += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print += ft_print_hex(c, va_arg(args, unsigned int));
	else if (c == '%')
		print += ft_putchar('%');
	return (print);
}
