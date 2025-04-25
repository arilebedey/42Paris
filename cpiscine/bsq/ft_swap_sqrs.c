/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sqrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:39:15 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 18:09:54 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_swap_sqrs(t_bsq *best, t_bsq *sqr)
{
	if ((*best).y == -1)
	{
		*best = *sqr;
		return ;
	}
	if (sqr->size > best->size)
	{
		*best = *sqr;
		return ;
	}
	if (sqr->size == best->size)
	{
		if (sqr->y < best->y)
		{
			*best = *sqr;
			return ;
		}
		if (sqr->x < best->x && !(best->y < sqr->y))
		{
			*best = *sqr;
			return ;
		}
	}
	return ;
}
/*
int	main(void)
{
	printf("#### sqr size %i, best size %i\n", sqr->size, best->size);
			int	i;
			t_bsq	sqr;
			sqr.y = 0;
			sqr.x = 3;
			sqr.size = 1;
			t_bsq	best;
			best.y = 1;
			best.x = 3;
			best.size = 1;
			printf("y: %i x: %i size: %i <-- \n", best.y, best.x, best.size);
			printf("y: %i x: %i size: %i <-- \n", sqr.y, sqr.x, sqr.size);
			ft_swap_sqrs(&best, &sqr);
			printf("y: %i x: %i size: %i <-- \n", best.y, best.x, best.size);
			best.y = 2;
			best.x = 3;
			best.size = 1;
			printf("y: %i x: %i size: %i <-- \n", sqr.y, sqr.x, sqr.size);
			printf("y: %i x: %i size: %i <-- \n", best.y, best.x, best.size);
}
*/
