/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:10:22 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/16 10:10:22 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(char *s, char *ss, int n)
{
	int	x;

	x = 0;
	while (x < n && s[x] == ss[x])
		x++;
	if (x == n)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	char	*buff;
	char	*tmp;
	char	c;
	int		r;
	int		x;
	int		len;

	buff = malloc(1000000);
	tmp = av[1];
	r = read(0, &c, 1);
	x = 0;
	len = strlen(av[1]);
	(void)ac;
	while (r > 0)
	{
		buff[x++] = c;
		r = read(0, &c, 1);
	}
	buff[x] = '\0';
	x = 0;
	while (buff[x] != '\0')
	{
		if (ft_strncmp(&buff[x], tmp, len) == 1)
		{
			for (int y = 0; y < len; y++)
				write(1, "*", 1);
			x += len;
		}
		else
		{
			write(1, &buff[x], 1);
			x++;
		}
	}
	free(buff);
}
