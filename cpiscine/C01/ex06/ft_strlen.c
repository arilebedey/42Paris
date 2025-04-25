/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:54:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/18 19:21:03 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int nb;
	nb = ft_strlen("sdkjcdsc");
	printf("%i\n", nb);
}
*/
