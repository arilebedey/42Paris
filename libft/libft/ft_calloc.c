/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:08:23 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:24 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This file implements ft_calloc with four key security considerations:      */
/* 1. The (size_t)-1 represents the maximum value a size_t can hold           */
/* 2. (size_t)-1 / size calculates max elements that won't overflow           */
/* 3. count > ((size_t)-1 / size) checks if multiplication would overflow     */
/* 4. size != 0 prevents division by zero in the calculation                  */
/* ************************************************************************** */

#include "libft.h"

static void	*zeroalloc(size_t size)
{
	void	*mem_ptr;
	size_t	i;

	mem_ptr = malloc(size);
	if (!mem_ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(char *)(mem_ptr + i) = 0;
		i++;
	}
	return (mem_ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	return (zeroalloc(count * size));
}
