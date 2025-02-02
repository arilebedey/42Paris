/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:04:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/02 12:04:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*range;
	int	min;
	int	max;

	//min = -100000000;
	//max = 100000000;
	min = -1;
	max = 21;
	ft_ultimate_range(&range, min, max);
	for(int i = 0; i < (max - min); i++)
		printf("%i ", range[i]);
}
*/
