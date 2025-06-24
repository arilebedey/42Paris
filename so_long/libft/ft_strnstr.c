/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:49:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/05 11:14:30 by alebedev         ###   ########.fr       */
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
	size_t	ndl_len;
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	ndl_len = ft_strlen(needle);
	i = 0;
	if (max_len < ndl_len)
		return (NULL);
	while (haystack[i] && i < max_len)
	{
		j = 0;
		while (j < ndl_len && i + j < max_len && needle[j] == haystack[j + i])
			j++;
		if (j == ndl_len)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
