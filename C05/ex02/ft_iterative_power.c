/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:28:28 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 15:48:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	nbr = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nbr * nb;
		power--;
	}
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_power(4, 4));
	printf("%i\n", ft_iterative_power(2, 5));
	printf("%i\n", ft_iterative_power(2, 4));
	printf("%i\n", ft_iterative_power(2, 3));
	printf("%i\n", ft_iterative_power(2, 2));
}
*/
