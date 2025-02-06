/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:41:22 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 18:15:04 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (src[i] && i < nb)
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "ABC";
	char	dest2[3] = "abc";
	strncat(dest2, src, 3);
	printf("%s\n", dest2);
	char	src2[] = "ABC";
	char	dest[3] = "abc";
	ft_strncat(dest, src, 3);
	printf("%s\n", dest);
}
*/
