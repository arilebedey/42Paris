/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:08:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/18 17:10:22 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_chars(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		return ;
	}
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write_chars(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}	
}
/*
int	main(void)
{
	ft_print_comb();
}
*/
