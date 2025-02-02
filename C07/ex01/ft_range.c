/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:04:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/31 11:42:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min;
	int	max;

	//min = -100000000;
	//max = 100000000;
	min = -1;
	max = 1;
	int	*tab;
	tab = ft_range(min, max);
	for(int i = 0; i < (max - min); i++)
		printf("%i ", tab[i]);
}
*/
