/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:41:22 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:16 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	len = 0;
	while (dest[len])
		len++;
	i = 0;
	while (src[i])
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
	char	src[4] = "ABC";
	char	dest[7] = "abc";
	ft_strcat(dest, src);
	printf("%s\n", dest); //abcABC
	char	src2[4] = "ABC";
	char	dest2[7] = "abc";
	strcat(dest2, src);
	printf("%s\n", dest2); //abc
}
*/
