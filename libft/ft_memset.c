/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:30 by alebedev          #+#    #+#             */
/*   Updated: 2025/03/17 12:36:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Sets a block of memory to a specified value.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}
/* #include <stdio.h> */
/* #include "libft.h" */
/* int main(void) */
/* { */
/*     // Example 1: Initialize an array with zeros */
/*     int numbers[5]; */
/*     ft_memset(numbers, 0, sizeof(numbers)); */
/*     printf("Array after ft_memset with 0:\n"); */
/*     for (int i = 0; i < 5; i++) */
/*         printf("%d", numbers[i]); */
/*     printf("\n\n"); */
/*      */
/*     // Example 2: Set a string buffer to a specific character */
/*     char buffer[10]; */
/*     ft_memset(buffer, 'A', 9); */
/*     buffer[9] = '\0';  // Null-terminate the string */
/*     printf("Buffer after ft_memset with 'A': %s\n\n", buffer); */
/*      */
/*     return 0; */
/* } */
