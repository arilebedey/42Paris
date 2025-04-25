/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:57:15 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/04 19:57:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_atoi(char *str, int index, int negative)
{
	int	atoi;

	atoi = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		atoi = atoi * 10 + str[index] - '0';
		index++;
	}
	return (negative * atoi);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negative;

	i = 0;
	negative = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				negative *= -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			return (get_atoi(str, i, negative));
		else
			return (0);
	}
	return (get_atoi(str, i, negative));
}
