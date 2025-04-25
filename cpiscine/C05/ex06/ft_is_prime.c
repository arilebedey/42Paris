/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:05:52 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 16:57:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_is_prime(6));
	printf("%i\n", ft_is_prime(98));

	printf("%i\n", ft_is_prime(2));
	printf("%i\n", ft_is_prime(5));
	printf("%i\n", ft_is_prime(97));
}
*/
