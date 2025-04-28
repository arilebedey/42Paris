/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:13:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/03/23 17:51:42 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** ft_strchr - Locates the first occurrence of a character in a string
**
** This function searches for the first occurrence of the character 'c'
** in the string 's'. The terminating null byte is considered part of the 
** string.
**
** @s: The string to search in
** @c: The character to search for
**
** Return: A pointer to the first occurrence of the character, or NULL if not
** found
**
** Note: Cast from const char* to char* is needed for return; would be
** unnecessary if both parameter and return type were char*.
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
