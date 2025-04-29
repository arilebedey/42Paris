/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:35:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/28 14:55:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	dst_index;
	size_t	i;

	dst_len = ft_strlen(d);
	dst_index = 0;
	while (d[dst_index])
		dst_index++;
	i = 0;
	while (s[i] && (i + dst_index + 1) < (dstsize))
	{
		d[dst_index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		d[dst_index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	else
		return (ft_strlen(s) + dst_len);
}
