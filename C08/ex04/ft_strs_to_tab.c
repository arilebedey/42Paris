/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:51:32 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/02 19:36:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof (char) * (ft_strlen(src) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	stock[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		stock[i].str = ft_strdup(av[i]);
		stock[i].copy = ft_strdup(stock[i].str);
		stock[i].size = ft_strlen(stock[i].str);
		i++;
	}
	return (stock);
}
/*
// TESTS
//
//
#include <unistd.h>
#include <stdio.h>
void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int find_last_stock(t_stock_str *stock)
{
	int i;

	i = 0;
	while (stock[i].str)
		i++;
	return (i);
}

void	ft_show_tab(t_stock_str *stock)
{
	int	len;
	int	i;

	len = find_last_stock(stock);
	i = 0;
	while (i < len)
	{
		ft_putstr(stock[i].str);
		ft_putstr("\n");
		ft_putnbr(stock[i].size);
		ft_putstr("\n");
		ft_putstr(stock[i].copy);
		ft_putstr("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	ft_strs_to_tab(ac, av);
	ft_show_tab(ft_strs_to_tab(ac, av));
	return (0);
}
*/
