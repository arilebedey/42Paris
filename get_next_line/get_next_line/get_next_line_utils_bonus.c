/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:45:41 by alebedev          #+#    #+#             */
/*   Updated: 2026/04/04 10:24:11 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*init_stash(char **stash, char *buffer)
{
	if (*stash)
		return (*stash);
	*stash = malloc(sizeof(char));
	if (!*stash)
	{
		free(buffer);
		return (NULL);
	}
	(*stash)[0] = '\0';
	return (*stash);
}

char	*ft_strjoin_free(char const *s1, char const *s2, size_t s1_len)
{
	char	*new;
	size_t	s2_len;
	size_t	i;

	s2_len = ft_strlen(s2);
	new = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new)
		return (free((char *)s1), NULL);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new[s1_len + i] = s2[i];
		i++;
	}
	new[s1_len + s2_len] = '\0';
	free((char *)s1);
	return (new);
}
