/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enlarge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:08 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 18:06:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_enlarge_check(char **map, t_bsq sqr)
{
	unsigned int	y_max;
	unsigned int	x_max;
	unsigned int	size;
	unsigned int	len;

	y_max = sqr.y + sqr.size;
	x_max = sqr.x + sqr.size;
	size = getmapidx(map);
	len = getlineidx(map);
	if (y_max <= size && x_max <= len)
		return (1);
	return (0);
}

t_bsq	*ft_enlarge_ovrwrt(t_bsq *sqr)
{
	sqr->size = (sqr->size + 1);
	return (sqr);
}
/*
int	main()
{
	printf("y: %i, x: %i, size: %i, steps: %i <-- enlarge \
   	check\n", sqr.y, sqr.x, sqr.size, sqr.steps);
	printf("size: %i, ymax %i <-- enlarge check\n", size, y_max);
			t_bsq	sqr;
			int	i;
			sqr.y = 1;
			sqr.x = 3;
			sqr.size = 1;
			//ft_newpos_ovrwrt(map, &sqr, info);
			i = ft_enlarge_check(map, sqr, info);
			printf("%i <- enlarge possible?\n", i);
}
*/
