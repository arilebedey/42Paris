/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:49:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/29 12:53:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Note on strnstr:
** - Locates first occurrence of needle in haystack, up to len chars
** - Returns haystack if needle is empty
** - Returns NULL if needle isn't found within len chars
** - Otherwise returns pointer to first match
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t max_len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	n_len = ft_strlen(needle);
	i = 0;
	if (max_len < n_len)
		return (NULL);
	while (haystack[i] && i < max_len)
	{
		j = 0;
		while (j < n_len && i + j < max_len && needle[j] == haystack[j + i])
			j++;
		if (j == n_len)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
