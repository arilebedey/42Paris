/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:25:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/02 15:54:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_top_a(t_context *ctx, t_stack_segmnt *seg,
		t_stack *stack, int max_val)
{
	if (stack->values[stack->newest_idx] == max_val)
}

void	sort_three_elements_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_stack	*stack;
	int		max_val;

	stack = stack_from_location(ctx, seg->location);
	max_val = segment_value(&ctx, seg);
	if (seg->location == LOCATION_TOP_A)
		sort_three_top_a(ctx, seg, stack, max_val);
	else if (seg->location == LOCATION_BOTTOM_A)
		sort_three_bottom_a(ctx, seg, stack, max_val);
	else if (seg->location == LOCATION_TOP_B)
		sort_three_top_b(ctx, seg, stack, max_val);
	else if (seg->location == LOCATION_BOTTOM_B)
		sort_three_bottom_b(ctx, seg, stack, max_val);
}
