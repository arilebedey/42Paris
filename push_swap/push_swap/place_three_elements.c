/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_three_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:25:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 14:12:50 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	sort_three_top_a(t_context *ctx, t_stack_segmnt *seg,
		t_stack *stack, int max_val)
{
	if (stack->values[stack->newest_idx] == max_val)
	{
		swap_a(ctx);
		rotate_a(ctx);
		swap_a(ctx);
		r_rotate_a(ctx);
	}
	else if (stack->values[get_next_bottom_idx(stack,
			stack->newest_idx)] == max_val)
	{
		rotate_a(ctx);
		swap_a(ctx);
		r_rotate_a(ctx);
	}
	seg->loc = LOCATION_TOP_A;
	seg->count -= 1;
	place_two_elements(ctx, seg);
}

static void	sort_three_top_b(t_context *ctx, t_stack_segmnt *seg,
		t_stack *stack, int max_val)
{
	if (stack->values[stack->newest_idx] == max_val)
		push_a(ctx);
	else if (stack->values[get_next_bottom_idx(stack,
			stack->newest_idx)] == max_val)
	{
		swap_b(ctx);
		push_a(ctx);
	}
	else
	{
		rotate_b(ctx);
		rotate_b(ctx);
		push_a(ctx);
		r_rotate_b(ctx);
		r_rotate_b(ctx);
	}
	push_a(ctx);
	push_a(ctx);
	seg->loc = LOCATION_TOP_A;
	seg->count -= 1;
	place_two_elements(ctx, seg);
}

static void	sort_three_bottom_a(t_context *ctx, t_stack_segmnt *seg,
		t_stack *stack, int max_val)
{
	r_rotate_a(ctx);
	r_rotate_a(ctx);
	if (stack->values[stack->newest_idx] == max_val)
	{
		swap_a(ctx);
		r_rotate_a(ctx);
	}
	else if (stack->values[get_next_top_idx(stack,
			stack->newest_idx)] == max_val)
		r_rotate_a(ctx);
	else
	{
		push_b(ctx);
		r_rotate_a(ctx);
		swap_a(ctx);
		push_a(ctx);
	}
	seg->loc = LOCATION_TOP_A;
	seg->count -= 1;
	place_two_elements(ctx, seg);
}

static void	sort_three_bottom_b(t_context *ctx, t_stack_segmnt *seg,
		t_stack *stack, int max_val)
{
	r_rotate_b(ctx);
	r_rotate_b(ctx);
	if (stack->values[stack->newest_idx] == max_val)
	{
		push_a(ctx);
		r_rotate_b(ctx);
	}
	else if (stack->values[get_next_top_idx(stack,
			stack->newest_idx)] == max_val)
	{
		swap_b(ctx);
		push_a(ctx);
		r_rotate_b(ctx);
	}
	else
	{
		r_rotate_b(ctx);
		push_a(ctx);
	}
	seg->loc = LOCATION_TOP_B;
	seg->count -= 1;
	place_two_elements(ctx, seg);
}

void	place_three_elements(t_context *ctx, t_stack_segmnt *seg)
{
	t_stack	*stack;
	int		max_val;

	stack = stack_from_location(ctx, seg->loc);
	max_val = segment_max_value(ctx, seg);
	if (seg->loc == LOCATION_TOP_A)
		sort_three_top_a(ctx, seg, stack, max_val);
	else if (seg->loc == LOCATION_BOTTOM_A)
		sort_three_bottom_a(ctx, seg, stack, max_val);
	else if (seg->loc == LOCATION_TOP_B)
		sort_three_top_b(ctx, seg, stack, max_val);
	else if (seg->loc == LOCATION_BOTTOM_B)
		sort_three_bottom_b(ctx, seg, stack, max_val);
}
