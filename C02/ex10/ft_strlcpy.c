/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:28:22 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/29 10:04:41 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "hellohello";
	char	dest[5] = "ABC";
	int		a;
	a = ft_strlcpy(dest, str, 1);
	printf("%i\n", a);
	printf("%s\n", dest);
	char	str2[] = "hellohello";
	char	dest2[5] = "ABC";
	int		b;
	b = ft_strlcpy(dest2, str2, 4);
	printf("%i\n", b);
	printf("%s\n", dest);
}
*/
