/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:05:52 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 17:13:37 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 1;
		}
		i++;
	}
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_find_next_prime(2));
	printf("%i\n", ft_find_next_prime(5));
	printf("%i\n", ft_find_next_prime(97));
	printf("%i\n", ft_find_next_prime(999));
}
*/
