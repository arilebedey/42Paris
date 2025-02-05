/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:26:53 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 21:56:03 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	*ft_newpos_check(char **map, t_bsq sqr, char *info, int was_incrm)
{
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	pos[0] = sqr.y;
	pos[1] = sqr.x;
	if (is_last(pos[0], pos[1], last_testable(map, info)))
		return (0);
	while (pos[0] <= getmapidx(map) && pos[1] <= getlineidx(map))
	{
		if (map[pos[0]][pos[1]] == info[0] && was_incrm != 0)
			return (pos);
		if (pos[1] == getlineidx(map))
		{
			if (pos[0] == getmapidx(map))
				return (0);
			(pos[0])++;
			pos[1] = 0;
		}
		else
			pos[1]++;
		was_incrm++;
	}
	return (pos);
}

int	ft_newpos_ovrwrt(char **map, t_bsq *sqr, char *info)
{
	int	*pos;

	if (sqr->x == -1)
	{
		pos = last_testable(map, info);
		if (!pos)
			return (0);
		pos = frst_testable(map, info);
		if (!pos)
			return (0);
		sqr->y = pos[0];
		sqr->x = pos[1];
		(sqr->steps)++;
		return (1);
	}
	if (is_last(sqr->y, sqr->x, last_testable(map, info)))
		return (0);
	pos = ft_newpos_check(map, *sqr, info, 0);
	if (!pos)
		return (0);
	sqr->y = pos[0];
	sqr->x = pos[1];
	sqr->size = 1;
	(sqr->steps)++;
	return (1);
}
/*
int	main(void)
{
			int	i;
			t_bsq	sqr;
			sqr.y = 0;
			sqr.x = 3;
			sqr.size = 1;

			printf("y: %i x: %i size: %i <-- \n", sqr.y, sqr.x, sqr.size);
			ft_newpos_ovrwrt(map, &sqr, info);
			printf("y: %i x: %i size: %i <-- \n", sqr.y, sqr.x, sqr.size);
}
*/
