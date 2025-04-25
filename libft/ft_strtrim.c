/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:22:40 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/09 12:53:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Function trims leading and trailing characters from s1 that match any      */
/* character in set. Returns a new allocated string with trimmed content.     */
/* Note: We use (char *) cast to convert const char * to char * for return    */
/* type compatibility, as the function must return a modifiable char pointer. */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_leading_chars(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		is_trim_char;

	is_trim_char = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		is_trim_char = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				is_trim_char = 1;
			j++;
		}
		if (!is_trim_char)
			break ;
		i++;
	}
	return ((char *)&s1[i]);
}

static char	*get_end_position(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		is_trim_char;

	is_trim_char = 0;
	i = ft_strlen(s1) - 1;
	j = 0;
	while (i > 0)
	{
		is_trim_char = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				is_trim_char = 1;
			j++;
		}
		if (!is_trim_char)
			break ;
		i--;
	}
	return ((char *)&s1[i]);
}

static char	*create_trimmed_string(char const *begin, char const *end)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * (end - begin + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (begin + i <= end)
	{
		result[i] = begin[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*res;

	begin = skip_leading_chars(s1, set);
	end = get_end_position(begin, set);
	if (!s1[0] || end < begin)
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
		res[0] = '\0';
	}
	else
		res = create_trimmed_string(begin, end);
	if (!res)
		return (NULL);
	return (res);
}
