/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:42:16 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/01 16:05:43 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	baselen;
	int	count;
	int	i;
	int	j;

	baselen = 0;
	while (base[baselen])
		baselen++;
	i = -1;
	while (++i < baselen)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32)
			return (0);
		count = 0;
		j = -1;
		while (++j < baselen)
		{
			if (base[i] == base[j] || (base[i] > 8 && base[i] < 14))
				count++;
		}
		if (count > 1)
			return (0);
	}
	return (1);
}

int	part_of_base(char c, char *base)
{
	int	baselen;
	int	i;

	i = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	while (i < baselen)
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	base_to_dec(char c, char *base)
{
	int	i;
	int	baselen;

	i = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	while (i < baselen)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	get_atoi(char *str, int index, int negative, char *base)
{
	int	atoi;
	int	baselen;
	int	check;

	atoi = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	check = check_base(base);
	if (baselen < 2)
		return (0);
	if (!check)
		return (0);
	while (part_of_base(str[index], base))
	{
		atoi = atoi * baselen + base_to_dec(str[index], base);
		index++;
	}
	return (negative * atoi);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negative;

	i = 0;
	negative = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				negative *= -1;
			i++;
		}
		if (part_of_base(str[i], base))
			return (get_atoi(str, i, negative, base));
		else
			return (0);
	}
	return (get_atoi(str, i, negative, base));
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	a;
	(void) argc;
	(void) argv;
	//char	*c = argv[1];
	//a = atoi(c);
	//a = ft_atoi_base("4E20F", "X123456789ABCDEF"); //4e20 --> 20000
	a = ft_atoi_base("   +  -----+++---1234567890", "0123456789"); //4e20 --> 20000
	printf("%i", a);
}
*/
