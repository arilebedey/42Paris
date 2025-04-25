/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:50:48 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/20 11:26:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	a;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	a = nb % 10 + '0';
	write(1, &a, 1);
}

int	get_min(int n)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (i < n)
	{
		nbr = nbr * 10 + i;
		i++;
	}
	return (nbr);
}

int	get_max(int n)
{
	int	nbr;

	nbr = 0;
	while (0 < n)
	{
		nbr = nbr * 10 + 10 - n;
		n--;
	}
	return (nbr);
}

int	check_number(int nbr, int n)
{
	int	i;
	int	j;

	if (n == 1)
		return (1);
	while (n > 0)
	{
		i = nbr % 10;
		nbr /= 10;
		j = nbr % 10;
		if (i <= j && j != 0)
			return (0);
		n--;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	nbr;
	int	max;
	int	zero_count;

	zero_count = 0;
	nbr = n + 1;
	while (--nbr > 0)
		zero_count = 1 + zero_count * 10;
	if (n == 1)
		zero_count = 0;
	nbr = get_min(n) - 1;
	max = get_max(n);
	while (++nbr != max)
	{
		if (check_number(nbr, n) && zero_count > 0)
			write(1, "0", 1);
		zero_count--;
		if (check_number(nbr, n) != 0)
		{
			ft_putnbr(nbr);
			write(1, ", ", 2);
		}
	}
	ft_putnbr(max);
}
/*
int	main(void)
{
	ft_print_combn(1);
	write(1, "\n\n", 2);
	ft_print_combn(2);
	write(1, "\n\n", 2);
	ft_print_combn(3);
	write(1, "\n\n", 2);
	ft_print_combn(4);
	write(1, "\n\n", 2);
	ft_print_combn(5);
	write(1, "\n\n", 2);
	ft_print_combn(6);
	write(1, "\n\n", 2);
	ft_print_combn(7);
	write(1, "\n\n", 2);
	ft_print_combn(8);
	write(1, "\n\n", 2);
	ft_print_combn(9);
	return (0);
}
*/
