/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:20:09 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/02 11:29:27 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delim(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_lastdelim(char *str, char *charset)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (!is_delim(str[i], charset))
	{
		if (i == 0)
			return (-1);
		i--;
	}
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	lastdelim;
	int	i;

	count = 0;
	lastdelim = ft_lastdelim(str, charset);
	i = 0;
	while (str[i] && i != lastdelim)
	{
		while (!is_delim(str[i], charset) && str[i])
			i++;
		while (is_delim(str[i], charset) && str[i] && i != lastdelim)
			i++;
		while (!is_delim(str[i], charset) && str[i])
		{
			if (!is_delim(str[i], charset) && str[i])
			{
				count++;
				while (!is_delim(str[i], charset) && str[i])
					i++;
			}
		}
	}
	return (count);
}

int	add_word(char **tab, char *str, int j, char *charset)
{
	int	i;
	int	k;

	i = 0;
	while (!is_delim(str[i], charset))
		i++;
	tab[j] = malloc(sizeof(char) * i);
	if (!tab[j])
		return (i);
	k = 0;
	while (!is_delim(str[k], charset) && str[k])
	{
		tab[j][k] = str[k];
		k++;
	}
	tab[j][k] = 0;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		lastdelim;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (0);
	tab[count_words(str, charset)] = 0;
	lastdelim = ft_lastdelim(str, charset);
	i = 0;
	j = 0;
	while (str[i] && i != lastdelim)
	{
		while (!is_delim(str[i], charset) && str[i])
			i++;
		while (is_delim(str[i], charset) && str[i] && i != lastdelim)
			i++;
		if (!is_delim(str[i], charset) && str[i])
		{
			i += add_word(tab, &str[i], j, charset);
			j++;
		}
	}
	return (tab);
}
/*
// TESTS
//
//
#include <stdio.h>

void print_tabtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	(void) ac;
	print_tabtab(ft_split(av[1], "zx "));
}
*/
