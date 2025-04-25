/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:42:16 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/01 16:07:37 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int				count;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < base_len(base))
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		count = 0;
		j = 0;
		while (j < base_len(base))
		{
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

char	get_char(int nbr, char *base)
{
	int	i;

	i = 0;
	while (i < nbr)
		i++;
	return (base[i]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	check;
	unsigned int	baselen;
	unsigned int	nb;
	char			c;

	check = check_base(base);
	if (!check)
		return ;
	baselen = base_len(base);
	if (baselen < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int) -nbr;
	}
	nb = (unsigned int) nbr;
	if (nb > baselen - 1)
		ft_putnbr_base(nb / baselen, base);
	nb = nb % baselen;
	c = get_char(nb, base);
	write(1, &c, 1);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a;
	char base[4];
	
	a = -2147483648;
	//base[0] = 'i';
	//base[1] = 'y';
	//base[2] = 31;
	//base[3] = 0;
	
	//ft_putnbr_base(a, base);
	ft_putnbr_base(a, "0123456789");
	ft_putnbr_base(32, "F123456789ABCDEF");
}
*/
