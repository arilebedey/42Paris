/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:13:52 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 21:50:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_solver(char **map, t_bsq *best, t_bsq *sqr, char *info)
{
	if (sqr->steps == max_steps(map, info))
		return ;
	if (sqr->x == -1)
	{
		ft_newpos_ovrwrt(map, sqr, info);
		ft_swap_sqrs(best, sqr);
	}
	if (ft_check_square(map, *sqr, info))
	{
		ft_swap_sqrs(best, sqr);
		if (ft_enlarge_check(map, *sqr))
			ft_solver(map, best, ft_enlarge_ovrwrt(sqr), info);
		else
		{
			ft_newpos_ovrwrt(map, sqr, info);
			ft_solver(map, best, sqr, info);
		}
	}
	else
	{
		ft_newpos_ovrwrt(map, sqr, info);
		ft_solver(map, best, sqr, info);
	}
}

t_bsq	ft_find(char **map, char *info)
{
	t_bsq	best;
	t_bsq	sqr;

	best.y = -1;
	best.x = -1;
	best.size = 1;
	best.steps = 0;
	sqr.y = -1;
	sqr.x = -1;
	sqr.size = 1;
	sqr.steps = 0;
	ft_solver(map, &best, &sqr, info);
	return (best);
}
/*

	printf("\n");
	printf("y: %i x: %i steps: %i <<- in solver", sqr->y, sqr->x, sqr->steps);
	printf("    %i <<- max steps", max_steps(map, info));
*/
