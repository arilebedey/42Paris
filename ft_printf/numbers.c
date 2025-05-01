/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:30 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 15:10:50 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	c = n % 10 + '0';
	count += ft_print_char(c);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	c = n % 10 + '0';
	count += ft_print_char(c);
	return (count);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	int		count;
	char	*hex_digits;

	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n > 15)
		count += ft_print_hex(n / 16, uppercase);
	count += ft_print_char(hex_digits[n % 16]);
	return (count);
}
