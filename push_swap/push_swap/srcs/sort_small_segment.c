/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:05:26 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/02 15:25:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_one_element(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->location == LOCATION_TOP_A || seg->location == LOCATION_TOP_B
		|| seg->location == LOCATION_BOTTOM_B)
		move_to_location(ctx, seg->location, LOCATION_TOP_A);
	seg->elem_count -= 1;
}

void	sort_two_elements(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->location == LOCATION_TOP_A || seg->location == LOCATION_TOP_B
		|| seg->location == LOCATION_BOTTOM_B)
	{
		move_to_location(ctx, seg->location, LOCATION_TOP_A);
		move_to_location(ctx, seg->location, LOCATION_TOP_A);
	}
	if (get_value_at(&ctx->stack_a, 1) > get_value_at(&ctx->stack_a, 2))
		swap_a(ctx);
	seg->elem_count -= 2;
}

/* NOTE : Effective when the segment is small, */
/* and located at LOCATION_TOP_A Breaks the loop if no immediate sorting  */
/* opportunity exists(i.e., top of stack A doesn’t match expected values). */
void	sort_small_segment(t_context *ctx, t_stack_segmnt *seg)
{
	int	seg_val_1;
	int	seg_val_2;

	while (seg->location != LOCATION_TOP_A && seg->elem_count)
	{
		seg_val_1 = segment_value(ctx, seg, 1);
		seg_val_2 = segment_value(ctx, seg, 2);
		if (seg_val_1 == get_value_at(&ctx->stack_a, 1) && seg->elem_count > 0)
			sort_one_element(ctx, seg);
		else if (seg_val_2 == get_value_at(&ctx->stack_a, 2
				&& seg->elem_count > 1) && seg->elem_count > 1)
			sort_small_second(ctx, seg);
		else
			break ;
	}
}
