/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:49:42 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/23 16:49:43 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof (char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char src[] = "kshofi34h9ehw394ffp9fjh30higw9uog98v4woi";
	char *dst;

	dst = ft_strdup(src);
	printf("%s\n", dst);
	free(dst);
}
*/
