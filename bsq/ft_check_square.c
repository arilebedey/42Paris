/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 18:04:22 by alebedev         ###   ########.fr       */
/*   Updated: 2025/02/04 13:13:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_square(char **map, t_bsq sqr, char *info)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = sqr.y;
	x = sqr.x;
	j = 0;
	while (j < sqr.size)
	{
		i = 0;
		while (i < sqr.size)
		{
			if (map[y + j][x + i] == info[1])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
/*
int	main(void)
{
printf("y: %i x: %i <- ft_check_square | element -> '%c'\n", \
y + j, x + i, map[y + j][x + i]);
			printf("sqr.size: %i\n", sqr.size);

				printf("FOUND WALL ft_check_sqr\n");

	printf("CHECK ft_check_sqr\n");

			t_bsq	sqr;
			int	i;
			sqr.y = 1;
			sqr.x = 3;
			sqr.size = 1;
			i = ft_check_square(map, sqr, info);
			printf("%i <- square possible ?\n", i);
}
*/
