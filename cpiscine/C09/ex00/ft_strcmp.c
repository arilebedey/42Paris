/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/21 13:37:09 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	d;
	char	s1[] = "ABC";
	char	s2[] = "AB";
	//d = ft_strcmp(s1, s2);
	d = strcmp(s1, s2);
	printf("%i\n", d);
}
*/
