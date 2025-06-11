/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:16:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/09 12:59:15 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	handle_top_b(t_context *ctx, t_stack_segmnt *seg)
{
	swap_b(ctx);
	push_a(ctx);
	if (value_at(&ctx->stack_b, 1) == value_at(&ctx->stack_a, 1) - 1)
	{
		push_a(ctx);
		seg->count--;
	}
}

static void	handle_bottom_a(t_context *ctx, t_stack_segmnt *seg)
{
	r_rotate_a(ctx);
	r_rotate_a(ctx);
	swap_a(ctx);
	if (value_at(&ctx->stack_a, 1) == value_at(&ctx->stack_a, 2) - 1)
		seg->count--;
	else
		rotate_a(ctx);
}

static void	handle_bottom_b(t_context *ctx, t_stack_segmnt *seg)
{
	r_rotate_b(ctx);
	r_rotate_b(ctx);
	push_a(ctx);
	if (value_at(&ctx->stack_b, 1) == value_at(&ctx->stack_a, 1) - 1)
	{
		push_a(ctx);
		seg->count--;
	}
	else
		rotate_b(ctx);
}

void	sort_small_second(t_context *ctx, t_stack_segmnt *seg)
{
	if (seg->loc == LOCATION_TOP_B)
		handle_top_b(ctx, seg);
	else if (seg->loc == LOCATION_BOTTOM_A)
		handle_bottom_a(ctx, seg);
	else if (seg->loc == LOCATION_BOTTOM_B)
		handle_bottom_b(ctx, seg);
	seg->count--;
}
