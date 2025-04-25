/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 11:39:11 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	a;
	(void) argc;
	char	*c = argv[1];
	//a = atoi(c);
	a = ft_atoi(c);
	printf("%i\n", a);
}
*/
