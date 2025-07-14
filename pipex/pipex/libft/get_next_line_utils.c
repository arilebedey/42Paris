/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:45:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/14 17:50:21 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

void	free_all(char *buffer, char *stash)
{
	free(buffer);
	free(stash);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free((char *)s1);
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*mem_ptr;

	if (size != 0 && count > ((size_t)-1 / size))
		return (NULL);
	mem_ptr = malloc(size * count);
	if (!mem_ptr)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		*(char *)(mem_ptr + i) = 0;
		i++;
	}
	return (mem_ptr);
}
