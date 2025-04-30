/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:10:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 14:21:18 by alebedev         ###   ########.fr       */
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
	else if (fmt_string == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (fmt_string == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (fmt_string == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (fmt_string == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(fmt_string);
	return (count);
}

int	ft_printf(const char *fmt_string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, fmt_string);
	while (fmt_string[i])
	{
		if (fmt_string[i] == '%' && fmt_string[i + 1])
		{
			count += ft_format_check(args, fmt_string[i + 1]);
			i++;
		}
		else if (fmt_string[i] != '%')
			count += ft_print_char(fmt_string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
