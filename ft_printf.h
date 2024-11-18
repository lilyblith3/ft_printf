/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzari <lzari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:27:10 by lzari             #+#    #+#             */
/*   Updated: 2024/11/17 17:38:10 by lzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_printf(char *format, ...);
int	ft_print_p(unsigned long ptr);
int	ft_print_num(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(char c, unsigned int n);
int	ft_format(const char c, va_list args);

#endif