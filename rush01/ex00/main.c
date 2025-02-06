/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:55:31 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/26 22:43:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#define ERROR "Error"
#include <stdio.h>

int	ft_test_arg(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab [i] <= 0 || tab [i] >= 5)
			return(0);
		i++;
	}
	if (i != 16)
		return (0);
	return (1);
}

int	*convert_str_int(char *argv[])
{
	int	i;
	int	*tab;
	int	len;
	char	**res;

	len = 0;
	while (argv[1][len])
		len++;
	res = malloc(sizeof(char *) * len);
	i = 0;
	while (i < len)
	{
		res [i] = malloc(sizeof(char) * 2);
		i++;
	}
	res = ft_split(argv[1], " ");
	tab = malloc(sizeof(int) * len);
	i = 0;
	while (res[i])
	{
		tab [i] = ft_atoi(res[i]);
		i++;
	}
	return (tab);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	result;
	int	*values;
	int	**tab;
	int	**tab_back;

	if (argc != 2)
		ft_putstr(ERROR);
	/*
	else
	{
		int	i;
		i = 0;
		values = convert_str_int(argv);
		for (int i = 0; i < 16; i++)
			printf("%i\n", values[i]);
	}
	*/
	tab = create_tab(4);
	tab_back = create_tab(4);

	genrow(tab, 0);
	genrow(tab_back, 0);
	values = convert_str_int(argv);
	result = gentab(tab, tab_back, values);
	int j = 0;
	while (j < 4)
	{
		for (int i = 0; i < 4; i++)
			printf("%i\t", tab[j][i]);
		printf("\n");
		j++;
	}
}
