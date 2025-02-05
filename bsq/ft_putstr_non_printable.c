/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:41:52 by agense            #+#    #+#             */
/*   Updated: 2025/01/28 13:52:57 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hexa(int dec_nbr, char *hexa_str)
{
	int		i;
	int		temp;
	int		save_dec_nbr;
	char	temp_hexa;

	i = 0;
	save_dec_nbr = dec_nbr;
	while (dec_nbr != 0)
	{
		temp = dec_nbr % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hexa_str[i] = temp;
		dec_nbr = dec_nbr / 16;
		i++;
	}
	temp_hexa = hexa_str[0];
	hexa_str[0] = hexa_str[1];
	hexa_str[1] = temp_hexa;
	if (save_dec_nbr <= 15)
		hexa_str[0] = '0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hexa_str[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			dec_to_hexa(str[i], hexa_str);
			ft_putchar('\\');
			ft_putchar(hexa_str[0]);
			ft_putchar(hexa_str[1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\\');
	ft_putchar('0');
	ft_putchar('0');
}
/*
int	main(void)
{
	char	chaine[15] = "ok ce-";
	chaine[6] = 19;
	chaine[7] = 21;
	chaine[8] = '-';
	chaine[9] = 127;
	chaine[10] = 30;
	ft_putstr_non_printable(chaine);
	return (0);
}*/
