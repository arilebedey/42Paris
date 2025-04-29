/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:37:23 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/23 16:37:23 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fac;

	if (nb < 0)
		return (0);
	fac = 1;
	if (nb > 0)
	{
		fac = ft_recursive_factorial(nb - 1);
		fac *= nb;
		return (fac);
	}
	else
		return (fac);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a;
	a = ft_recursive_factorial(-1);
	printf("%i\n", a);
	a = ft_recursive_factorial(0);
	printf("%i\n", a);
	a = ft_recursive_factorial(1);
	printf("%i\n", a);
	a = ft_recursive_factorial(2);
	printf("%i\n", a);
	a = ft_recursive_factorial(3);
	printf("%i\n", a);
}
*/
