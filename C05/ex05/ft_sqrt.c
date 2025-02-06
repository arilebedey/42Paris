/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:49:17 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 16:05:37 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	i = 1;
	sqrt = 0;
	if (nb < 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_sqrt(1));
	printf("%i\n", ft_sqrt(2));
	printf("%i\n", ft_sqrt(3));
	printf("%i\n", ft_sqrt(4));
	printf("%i\n", ft_sqrt(9));
	printf("%i\n", ft_sqrt(16));
	printf("%i\n", ft_sqrt(144));
	printf("%i\n", ft_sqrt(44435556));
}
*/
