/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:17:10 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 18:38:41 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = i;
			k = 0;
			while (str[j] == to_find[k])
			{
				if (to_find[k + 1] == 0)
					return (&str[i]);
				j++;
				k++;
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "abcdabcdzowedzow";
	char	to_find[] = "zowz";
	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n", strstr(str, to_find));
}	
*/
