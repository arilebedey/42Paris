/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:13:06 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/04 16:40:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_segment_to_top(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->loc == LOCATION_BOTTOM_A
		&& get_stack_size(&ctx->stack_a) == seg->count)
		seg->loc = LOCATION_TOP_A;
	if (seg->loc == LOCATION_BOTTOM_B
		&& get_stack_size(&ctx->stack_b) == seg->count)
		seg->loc = LOCATION_TOP_B;
}

t_stack	*stack_from_location(t_context *ctx, t_stack_location loc)
{
	if (loc == LOCATION_TOP_A || loc == LOCATION_BOTTOM_A)
		return (&ctx->stack_a);
	return (&ctx->stack_b);
}

int	segment_value(t_context *ctx, t_stack_segmnt *seg, int n)
{
	t_stack_location	loc;
	t_stack				*stack;
	int					idx;

	loc = seg->loc;
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

int	segment_max_value(t_context *ctx, t_stack_segmnt *seg)
{
	t_stack	*stack;
	int		count;
	int		max_val;
	int		idx;

	stack = stack_from_location(ctx, seg->loc);
	count = seg->count;
	max_val = 0;
	if (seg->loc == LOCATION_TOP_A || seg->loc == LOCATION_TOP_B)
		idx = stack->newest_idx;
	else
		idx = stack->oldest_idx;
	while (count--)
	{
		if (stack->values[idx] > max_val)
			max_val = stack->values[idx];
		if (seg->loc == LOCATION_TOP_A || seg->loc == LOCATION_TOP_B)
			idx = get_next_bottom_idx(stack, idx);
		else
			idx = get_next_top_idx(stack, idx);
	}
	return (max_val);
}
