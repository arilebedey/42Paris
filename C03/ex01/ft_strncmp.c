/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:12:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 16:27:35 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	d;
	char	s1[] = "AB";
	char	s2[] = "ABCD";
	d = ft_strncmp(s1, s2, 5);
	printf("%i\n", d);
	d = strncmp(s1, s2, 5);
	printf("%i\n", d);
}
*/
