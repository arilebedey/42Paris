/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:54:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 10:37:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char	str[5] = "hello";
	int	count;
	count = ft_strlen(str);
	printf("%i\n", count);
}
*/
