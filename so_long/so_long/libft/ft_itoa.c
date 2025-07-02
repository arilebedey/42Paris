/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:41:40 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/29 12:08:59 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_digit_count(long number)
{
	size_t	digit_count;

	digit_count = 0;
	if (number < 0)
	{
		number = number * -1;
		digit_count++;
	}
	if (number == 0)
		return (1);
	while (number)
	{
		number = number / 10;
		digit_count++;
	}
	return (digit_count);
}

char	*ft_itoa(int n)
{
	size_t	string_length;
	long	number_value;
	char	*result_string;
	size_t	negative_sign;

	string_length = calculate_digit_count((long) n);
	result_string = (char *) malloc(sizeof(char) * (string_length + 1));
	if (!result_string)
		return (NULL);
	number_value = (long) n;
	negative_sign = 0;
	if (number_value < 0)
	{
		number_value = number_value * (-1);
		result_string[0] = '-';
		negative_sign = 1;
	}
	result_string[string_length] = 0;
	while (string_length > negative_sign)
	{
		result_string[string_length - 1] = number_value % 10 + '0';
		number_value = number_value / 10;
		string_length--;
	}
	return (result_string);
}
