/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:16:31 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/18 14:58:52 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static int	add_word(char **tab, char *str, int j, char c)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	tab[j] = malloc(sizeof(char) * (i + 1));
	if (!tab[j])
		return (-1);
	k = 0;
	while (k < i)
	{
		tab[j][k] = str[k];
		k++;
	}
	tab[j][k] = 0;
	return (i);
}

static char	**process_words(char **tab, char *str, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			word_len = add_word(tab, &str[i], j, c);
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

static char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		words;

	words = count_words((char *)str, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	return (process_words(tab, (char *)str, c));
}

char	**parse_args(int *argc, char **argv)
{
	char	**args;
	int		count;

	if (*argc == 2)
	{
		if (!argv[1][0])
			early_error();
		args = ft_split(argv[1], ' ');
		if (!args)
			early_error();
		count = 0;
		while (args[count])
			count++;
		*argc = count + 1;
		return (args);
	}
	return (argv + 1);
}
