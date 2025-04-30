/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:10:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 13:14:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_format_check(va_list args, const char fmt_string)
{
	int	count;

	count = 0;
	if (fmt_string == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (fmt_string == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (fmt_string == 'd' || fmt_string == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (fmt_string == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (fmt_string == '%')
		count += ft_print_char('%');
	else if (fmt_string == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (fmt_string == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else
		count += ft_print_char(fmt_string);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format_check(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
