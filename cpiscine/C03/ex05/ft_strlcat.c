/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:01:13 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/27 10:41:34 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;
	unsigned int	comp;

	srclen = str_len(src);
	i = 0;
	while (dest[i])
		i++;
	if (size > i)
		comp = i + srclen;
	else
		comp = size + srclen;
	if (size == 0)
		return (comp);
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (comp);
}
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	unsigned int	a;
	char	dest[8] = "abcd";
	char	src[] = "XYZXY";
	a = ft_strlcat(dest, src, 18);
	printf("%i\n", a);
	for(int i = 0; i < 18; i++)
		printf("%c", dest[i]);
	printf("\n");
	
	unsigned int	b;
	char	dest2[8] = "abcd";
	char	src2[] = "XYZXY";
	b = strlcat(dest2, src2, 18);
	printf("%i\n", b);
	for(int i = 0; i < 18; i++)
		printf("%c", dest2[i]);
	printf("\n");
}
