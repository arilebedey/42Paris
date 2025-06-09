/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:05:26 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/09 13:59:06 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_one_element(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->loc == LOCATION_TOP_A || seg->loc == LOCATION_TOP_B
		|| seg->loc == LOCATION_BOTTOM_B)
		move_to_loc(ctx, seg->loc, LOCATION_TOP_A);
	seg->count -= 1;
}

void	sort_two_elements(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->loc == LOCATION_BOTTOM_A || seg->loc == LOCATION_TOP_B
		|| seg->loc == LOCATION_BOTTOM_B)
	{
		move_to_loc(ctx, seg->loc, LOCATION_TOP_A);
		move_to_loc(ctx, seg->loc, LOCATION_TOP_A);
	}
	if (value_at(&ctx->stack_a, 1) > value_at(&ctx->stack_a, 2))
		swap_a(ctx);
	seg->count -= 2;
}

/* NOTE : Effective when the segment is small, */
/* and located at LOCATION_TOP_A Breaks the loop if no immediate sorting  */
/* opportunity exists(i.e., top of stack A doesn’t match expected values). */
void	sort_small_segment(t_context *ctx, t_stack_segmnt *seg)
{
	int	seg_val_1;
	int	seg_val_2;

	while (seg->loc != LOCATION_TOP_A && seg->count)
	{
		seg_val_1 = segment_value(ctx, seg, 1);
		seg_val_2 = segment_value(ctx, seg, 2);
		if (seg_val_1 == value_at(&ctx->stack_a, 1) && seg->count > 0)
			sort_one_element(ctx, seg);
		else if ((seg_val_2 == value_at(&ctx->stack_a, 2)) && seg->count > 1)
			sort_small_second(ctx, seg);
		else
			break ;
	}
}
