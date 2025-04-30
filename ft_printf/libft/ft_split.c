/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:20:09 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 12:16:16 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_delim(char c, char *set)
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

static int	count_words(char *str, char *charset)
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

static int	add_word(char **tab, char *str, int j, char *charset)
{
	int	i;
	int	k;

	i = 0;
	while (!is_delim(str[i], charset) && str[i])
		i++;
	tab[j] = malloc(sizeof(char) * (i + 1));
	if (!tab[j])
		return (-1);
	k = 0;
	while (!is_delim(str[k], charset) && str[k])
	{
		tab[j][k] = str[k];
		k++;
	}
	tab[j][k] = 0;
	return (i);
}

static char	**process_words(char **tab, char *str, char *charset)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_delim(str[i], charset) && str[i])
			i++;
		if (!is_delim(str[i], charset) && str[i])
		{
			word_len = add_word(tab, &str[i], j, charset);
			if (word_len == -1)
			{
				while (j > 0)
					free(tab[--j]);
				free(tab);
				return (NULL);
			}
			i += word_len;
			j++;
		}
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;

	words = count_words(str, charset);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	return (process_words(tab, str, charset));
}
