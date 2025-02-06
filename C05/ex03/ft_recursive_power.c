/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:28:28 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 17:17:59 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_recursive_power(4, 4));
	printf("%i\n", ft_recursive_power(2, 5));
	printf("%i\n", ft_recursive_power(2, 4));
	printf("%i\n", ft_recursive_power(2, 3));
	printf("%i\n", ft_recursive_power(2, 2));
}
*/
