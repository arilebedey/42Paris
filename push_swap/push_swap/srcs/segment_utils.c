/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:13:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/28 14:49:32 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* WARN: Untested code */
/* NOTE: */
/* Ensures the segment is marked as being at the top of its stack, */
/* avoiding unnecessary rotations or moves in functions like sort_segment */
/* or split_segment. */
/* Simplifies logic in recursive sorting by assuming segments are at the top */
/* when they span the entire stack. */
void	move_segment_to_top(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->location == LOCATION_BOTTOM_A
		&& get_stack_size(&ctx->stack_a) == seg->elem_count)
		seg->location = LOCATION_TOP_A;
	if (seg->location == LOCATION_BOTTOM_B
		&& get_stack_size(&ctx->stack_b) == seg->elem_count)
		seg->location = LOCATION_TOP_B;
}

t_stack	*stack_from_location(t_context *ctx, t_stack_location loc)
{
	if (loc == LOCATION_TOP_A || LOCATION_BOTTOM_A)
		return (&ctx->stack_a);
	return (&ctx->stack_b);
}

int	segment_value(t_context *ctx, t_stack_segmnt *seg, int n)
{
	t_stack_location	loc;
	t_stack				*stack;
	int					idx;

	loc = seg->location;
	stack = stack_from_location(ctx, loc);
	if (loc == LOCATION_TOP_A || loc == LOCATION_TOP_B)
		idx = stack->newest_idx;
	else
		idx = stack->oldest_idx;
	if (loc == LOCATION_TOP_A || loc == LOCATION_TOP_B)
		while (--n > 0)
			idx = get_next_bottom_idx(stack, idx);
	else
		while (--n > 0)
			idx = get_next_top_idx(stack, idx);
	return (stack->values[idx]);
}
