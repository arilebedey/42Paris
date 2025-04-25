/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:13:40 by alebedev          #+#    #+#             */
/*   Updated: 2025/03/26 16:28:11 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Key validations:                                                           */
/* 1. If start is beyond string end, create empty string                      */
/* 2. Limit extraction length to available characters                         */
/* 3. Only copy until string end or requested length                          */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t int	i;

	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
