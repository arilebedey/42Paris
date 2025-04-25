/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:20:09 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 17:28:15 by agense           ###   ########.fr       */
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

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_delim(str[i], charset) && str[i])
			i++;
		if (!is_delim(str[i], charset) && str[i])
		{
			count++;
			while (!is_delim(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

int	add_word(char **tab, char *str, int j, char *charset)
{
	int	i;
	int	k;

	i = 0;
	while (!is_delim(str[i], charset) && str[i])
		i++;
	tab[j] = malloc(sizeof(char) * (i + 1));
	if (!tab[j])
		return (0);
	k = 0;
	while (!is_delim(str[k], charset) && str[k])
	{
		tab[j][k] = str[k];
		k++;
	}
	tab[j][k] = 0;
	return (i);
}

char	**ft_split2(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (0);
	tab[count_words(str, charset)] = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_delim(str[i], charset))
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
	print_tabtab(ft_split(av[1], "/"));
}
*/
