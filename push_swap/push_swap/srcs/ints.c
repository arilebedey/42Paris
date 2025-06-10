/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:14:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/10 16:58:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	process_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	if (str[i] == 0)
		return (0);
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == 0)
			return (0);
	}
	return (sign);
}

bool	is_valid_int(char *str)
{
	int			i;
	long long	num;
	int			sign;

	sign = process_sign(str);
	if (sign == 0)
		return (false);
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 &&
				-num < (long long)INT_MIN))
			return (false);
		i++;
	}
	return (true);
}
