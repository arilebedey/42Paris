/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:46:29 by alebedev          #+#    #+#             */
/*   Updated: 2025/03/23 13:46:31 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** ft_memmove - Copies 'len' bytes from 'src' to 'dst', handling overlap
**
** This function chooses the copy direction based on pointer positions:
**
** 1. If dst < src (destination is before source):
**    - Copies forward (low address to high address)
**    - Safe because we read from source before overwriting destination
**
** 2. If dst > src (destination is after source):
**    - Copies backward (high address to low address)
**    - Prevents overwriting source data that hasn't been copied yet
**
** Note on unsigned char casting:
** unsigned char* pointers have special exemption from strict aliasing.
** The C standard (C11 6.5p7) allows these pointers to access any data type,
** making them ideal for memory manipulation functions.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	return (dst);
}
