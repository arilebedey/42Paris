/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:13:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 11:39:35 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** ft_strchr - Locates the first occurrence of a character in a string
**
** This function searches for the first occurrence of the character 'c'
** in the string 's'. The terminating null byte is considered part of the 
** string.
**/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			break ;
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}
