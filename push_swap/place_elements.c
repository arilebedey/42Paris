/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:05:26 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/12 16:54:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	place_one_element(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->loc == LOCATION_BOTTOM_A || seg->loc == LOCATION_TOP_B
		|| seg->loc == LOCATION_BOTTOM_B)
		move_to_loc(ctx, seg->loc, LOCATION_TOP_A);
	seg->count -= 1;
}

void	place_two_elements(t_context *ctx, t_stack_segmnt *seg)
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

static void	log_compared_values(int seg_val_1, int seg_val_2, int stk_val_1)
{
	printf("seg_val_1: %d, seg_val_2: %d, stk_val_1: %d\n", seg_val_1,
		seg_val_2, stk_val_1);
}

void	place_elements(t_context *ctx, t_stack_segmnt *seg)
{
	int	seg_val_1;
	int	seg_val_2;
	int	stk_val_1;

	if (seg->loc != LOCATION_TOP_A && seg->count)
	{
		printf("** Start push_a_if_consec: ");
		stk_val_1 = value_at(&ctx->stack_a, 1);
		seg_val_1 = segment_value(ctx, seg, 1);
		seg_val_2 = segment_value(ctx, seg, 2);
		log_compared_values(seg_val_1, seg_val_2, stk_val_1);
		if (seg_val_1 + 1 == stk_val_1 && seg->count > 0)
			place_one_element(ctx, seg);
		else if ((seg_val_2 + 1 == stk_val_1) && seg->count > 1)
		{
			printf("Running sort_second_top_a\n");
			place_second_elem(ctx, seg);
		}
	}
}
