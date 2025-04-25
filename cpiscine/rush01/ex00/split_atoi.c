/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:50:28 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/25 14:23:21 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset [i])
	{
		if (c == charset [i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copystring(char *str, int start, int end)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	while (i < end - start)
	{
		res [i] = str [start + i];
		i++;
	}
	res [i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		debut;

	i = 0;
	j = 0;
	debut = 0;
	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str [i])
	{
		while (str [i] && ft_is_charset(str [i], charset))
			i++;
		debut = i;
		while (!ft_is_charset(str [i], charset) && str [i])
			i++;
		if (debut < i)
			res [j++] = ft_copystring(str, debut, i);
	}
	res [j] = NULL;
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str [i] >= 48 && str [i] <= 57)
	{
		result = result * 10 + (str [i] - 48);
		i++;
	}
	if (str[i] != 0)
	{
		return (0);
	}
	return (result);
}
