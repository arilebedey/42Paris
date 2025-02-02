/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:53:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/30 11:44:55 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_dec_in_hex(int n)
{
	int		temp;
	char	a;
	char	b;

	if (n >= 16)
		put_dec_in_hex(n / 16);
	temp = n % 16;
	if (temp < 10)
	{
		a = temp + '0';
		write(1, &a, 1);
	}
	else
	{
		temp -= 9;
		b = temp + 96;
		write(1, &b, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	unsigned char *ustr;


	ustr = (unsigned char *) str;
	i = 0;
	while (ustr[i])
	{
		if (ustr[i] < 32 || ustr[i] > 126)
		{
			write(1, "\\", 1);
			if (ustr[i] >= 0 && ustr[i] <= 15)
				write(1, "0", 1);
			put_dec_in_hex(ustr[i]);
		}
		else
			write(1, &ustr[i], 1);
		i++;
	}
	write(1, "\\00", 3);
}
#include <stdio.h>
int	main(void)
{
	char	str[4];
	str[0] = -23; //--> \0f
	str[1] = 14; //--> \0e
	str[2] = 27; //--> \1b
	str[3] = 0;  //--> \00
	char	str2[] = "€";
	ft_putstr_non_printable(str);
	printf("\n");
	ft_putstr_non_printable(str2);
}
