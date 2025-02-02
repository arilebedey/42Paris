/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:24:11 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/20 11:55:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
	{
		return (1);
	}
	while (str[i] != 0)
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	int a1;
	int a2;
	int a3;
	char *str1 = ""; //1
	char *str2 = "HRLLO"; //1
	char *str3 = "FJDJDE;"; //0
	a1 = ft_str_is_uppercase(str1);
	a2 = ft_str_is_uppercase(str2);
	a3 = ft_str_is_uppercase(str3);

	printf("%i\n", a1);
	printf("%i\n", a2);
	printf("%i\n", a3);
}
*/
