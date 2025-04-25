/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:24:11 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/20 13:01:08 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "kahkehdkejhdkw";
	//str = ft_strupcase(str);
	ft_strupcase(str);

	printf("%s\n", str);
}
*/
