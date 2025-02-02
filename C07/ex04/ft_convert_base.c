/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:47:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/01 16:01:02 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	intlen(int nb, char *base)
{
	int	baselen;
	int	i;

	i = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	if (nb < 0)
		i++;
	nb = -nb;
	while (nb != 0)
	{
		nb /= baselen;
		i++;
	}
	return (i);
}

char	get_char(int nbr, char *base)
{
	int	i;

	i = 0;
	while (i < nbr)
		i++;
	return (base[i]);
}

void	ft_itoa_base(int nbr, char *base, char *itoa, int i)
{
	unsigned int	baselen;
	unsigned int	nb;
	char			c;

	if (!check_base(base))
		return ;
	baselen = 0;
	while (base[baselen])
		baselen++;
	if (baselen < 2)
		return ;
	if (nbr < 0)
	{
		itoa[0] = '-';
		nb = (unsigned int) -nbr;
	}
	else
		nb = (unsigned int) nbr;
	if (nb > baselen - 1)
		ft_itoa_base(nb / baselen, base, itoa, i - 1);
	nb = nb % baselen;
	c = get_char(nb, base);
	write(1, &c, 1);
	itoa[i] = c;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		atoi;
	char	*itoa;

	if (!(check_base(base_from) && check_base(base_to)))
		return (0);
	atoi = ft_atoi_base(nbr, base_from);
	itoa = malloc(sizeof(char) * (intlen(atoi, base_to) + 1));
	if (!itoa)
		return (0);
	ft_itoa_base(atoi, base_to, itoa, intlen(atoi, base_to) - 1);
	return (itoa);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	char	*res;
	char	base[] = "-0123456789";
	char	base16[] = "0123456789abcdef";
	res = ft_convert_base(av[1], base, base16);
	if (!res)
		printf("Null pointer");
	else
	{
		printf("\n%s <- res\n", res);
		printf("%i <- end ascii\n", res[intlen(ft_atoi_base(av[1], base), base)]);
	}
	return (0);
}
*/
