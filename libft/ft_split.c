/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:30:40 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/09 13:40:57 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_delimiter(str[i], charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*extract_word(char *str, char *charset, int *i)
{
	char	*word;
	int		len;
	int		j;

	len = 0;
	while (str[*i + len] && !is_delimiter(str[*i + len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = str[*i + j];
		j++;
	}
	word[j] = '\0';
	*i += len;
	return (word);
}

char	**allocate_result(char *str, char *charset)
{
	char	**result;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	result = allocate_result(str, charset);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_delimiter(str[i], charset))
			i++;
		if (str[i])
		{
			result[j] = extract_word(str, charset, &i);
			if (!result[j])
				return (NULL);
			j++;
		}
	}
	result[j] = 0;
	return (result);
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
	char **result;
	int	i;

	(void) ac;
	if (ac > 1)
	{
		result = ft_split(av[1], "zx ");
		if (result)
		{
			print_tabtab(result);
			i = 0;
			while (result[i])
				free(result[i++]);
			free(result);
		}
	}
	return (0);
}
*/
