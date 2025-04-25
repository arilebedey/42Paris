/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:34:31 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/02 12:14:57 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strs_len(char **strs, int size)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		i++;
	}
	return (count);
}

void	ft_concat(char *str, int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			str[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	str[k] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size - 1)
	{
		len += ft_strlen(sep);
		i++;
	}
	len += ft_strs_len(strs, size);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (size == 0)
	{
		str[0] = 0;
		return (str);
	}
	if (!str)
		return (0);
	ft_concat(str, size, strs, sep);
	return (str);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i\n", ft_strs_len(&argv[1], 3));
	printf("%s\n", ft_strjoin(3, &argv[1], "***"));
	//printf("%s\n", ft_strjoin(0, &argv[1], "***"));
	return (0);
}
*/
