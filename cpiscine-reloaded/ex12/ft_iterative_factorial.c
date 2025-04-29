/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:36:43 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/23 16:36:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fac;

	if (nb < 0)
		return (0);
	i = 0;
	fac = 1;
	while (++i < nb)
		fac = fac * (i + 1);
	return (fac);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a;
	a = ft_iterative_factorial(-1);
	printf("%i\n", a);
	a = ft_iterative_factorial(0);
	printf("%i\n", a);
	a = ft_iterative_factorial(1);
	printf("%i\n", a);
	a = ft_iterative_factorial(2);
	printf("%i\n", a);
	a = ft_iterative_factorial(3);
	printf("%i\n", a);
}
*/
