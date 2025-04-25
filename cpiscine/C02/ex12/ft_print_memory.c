/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:42:13 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/28 21:51:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	putstr(char *str, int long long k)
{
	int	i;

	if (k != -1)
	{
		if (k % 2 == 1)
			write(1, "   ", 3);
		if (k % 2 == 0)
			write(1, "  ", 2);
	}
	else
	{
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	putnbr_hex(long long int addr)
{
	long long	i;
	char		*base;

	base = "0123456789abcdef";
	if (addr > 15)
		putnbr_hex(addr / 16);
	i = 0;
	while (i < addr % 16)
		i++;
	write(1, &base[i], 1);
}

void	print_hex_ptr(void *addr, long long int idx)
{
	long long int	dec_addr;
	long long int	tmp;
	int				i;

	i = 0;
	dec_addr = (long long int) &addr[idx];
	tmp = dec_addr;
	while (tmp != 0)
	{
		tmp /= 16;
		i++;
	}
	i = 16 - i;
	while (i > 0)
	{
		putstr("0", -1);
		i--;
	}
	putnbr_hex(dec_addr);
	putstr(": ", -1);
}

void	print_addr_cols(void *addr, long long int i, long long int j, int size)
{
	long long int	k;
	long long int	dec_asc;

	while (++j < i + 16 && j < size)
	{
		dec_asc = ((char *) addr)[j];
		if (dec_asc < 16)
			putstr("0", -1);
		if (j % 2 == 0)
			putnbr_hex(dec_asc);
		if (j % 2 == 1)
		{
			putnbr_hex(dec_asc);
			putstr(" ", -1);
		}
		if (j == size - 1)
		{
			k = 0;
			while (++k < (i + 16 - j))
				putstr("", k);
		}	
	}
}

void	*ft_print_memory(void *addr, int size)
{
	long long int	dec_asc;
	long long int	i;
	long long int	j;

	if (size == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			print_hex_ptr(addr, i);
			j = i - 1;
			print_addr_cols(addr, i, j, size);
		}
		dec_asc = ((char *) addr)[i];
		if (dec_asc < 32 || dec_asc > 126)
			putstr(".", -1);
		else
			write(1, &dec_asc, 1);
		if (i % 16 == 15)
			putstr("\n", -1);
	}
	putstr("\n", -1);
	return (addr);
}
/*
#include <string.h>
int	main(void)
{
	char str[] = "Bonjour_les_amieut_faire_avec_print_memory";
	char str2[4];

	str2[0] = 1;
	str2[1] = 31;
	str2[2] = 127;
	str2[3] = 0;
	ft_print_memory(str, strlen(str));
	putstr("\n", -1);
	ft_print_memory(str2, 4);
	ft_print_memory(str, 0);
}
*/
