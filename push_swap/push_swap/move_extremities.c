/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_extremities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:51:52 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/10 16:42:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	move_from_top_a(t_context *ctx, t_stack_location to)
{
	if (to == LOCATION_TOP_B)
		push_b(ctx);
	else if (to == LOCATION_BOTTOM_A)
		rotate_a(ctx);
	else if (to == LOCATION_BOTTOM_B)
	{
		push_b(ctx);
		rotate_b(ctx);
	}
}

static void	move_from_top_b(t_context *ctx, t_stack_location to)
{
	if (to == LOCATION_TOP_A)
		push_a(ctx);
	else if (to == LOCATION_BOTTOM_B)
		rotate_b(ctx);
	else if (to == LOCATION_BOTTOM_A)
	{
		push_a(ctx);
		rotate_a(ctx);
	}
}

static void	move_from_bottom_a(t_context *ctx, t_stack_location to)
{
	if (to == LOCATION_TOP_A)
		r_rotate_a(ctx);
	else if (to == LOCATION_TOP_B)
	{
		r_rotate_a(ctx);
		push_b(ctx);
	}
	else if (to == LOCATION_BOTTOM_B)
	{
		r_rotate_a(ctx);
		push_b(ctx);
		rotate_b(ctx);
	}
}

static void	move_from_bottom_b(t_context *ctx, t_stack_location to)
{
	if (to == LOCATION_TOP_B)
		r_rotate_b(ctx);
	else if (to == LOCATION_BOTTOM_A)
	{
		r_rotate_b(ctx);
		push_a(ctx);
		rotate_a(ctx);
	}
	else if (to == LOCATION_TOP_A)
	{
		r_rotate_b(ctx);
		push_a(ctx);
	}
}

int	move_to_loc(t_context *ctx, t_stack_location from, t_stack_location to)
{
	if (from == LOCATION_TOP_A)
		move_from_top_a(ctx, to);
	else if (from == LOCATION_TOP_B)
		move_from_top_b(ctx, to);
	else if (from == LOCATION_BOTTOM_A)
		move_from_bottom_a(ctx, to);
	else if (from == LOCATION_BOTTOM_B)
		move_from_bottom_b(ctx, to);
	return (1);
}
