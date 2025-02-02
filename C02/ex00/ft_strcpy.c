/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:42:26 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/20 19:46:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str1[6] = "hello";
	char dest1[6] = "";
	char str2[6] = "hello";
	char dest2[6] = "";
	strcpy(dest1, str1);
	printf("%s\n", dest1);
	ft_strcpy(dest2, str2);
	printf("%s\n", dest2);
}
*/
