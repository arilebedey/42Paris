/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:55:23 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 11:42:23 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Casting to unsigned char ensures C standard compliance (ISO/IEC 9899), as the
** standard explicitly specifies that strncmp should compare as unsigned char.
** 
** This casting guarantees consistent behavior across all platforms regardless
** of whether char is signed or unsigned by default on the system.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
