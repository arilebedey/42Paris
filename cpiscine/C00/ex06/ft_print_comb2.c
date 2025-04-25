/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:08:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/18 17:07:17 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_comb(int a, int b)
{
	char	i;
	char	j;
	char	k;
	char	l;

	i = a / 10 + '0';
	j = a % 10 + '0';
	k = b / 10 + '0';
	l = b % 10 + '0';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, " ", 1);
	write(1, &k, 1);
	write(1, &l, 1);
	if (!(a == 98 && b == 99))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			write_comb(a, b);
			b++;
		}
		a++;
	}	
}
/*
int main(void)
{
	ft_print_comb2();
	return (0);
}
*/
