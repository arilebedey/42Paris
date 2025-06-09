/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:24:08 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/09 14:01:13 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_stack_a_part_sorted(t_context *ctx, int start_pos)
{
	int	i;
	int	val;

	i = ctx->stack_a.newest_idx;
	while (--start_pos)
		i = get_next_bottom_idx(&ctx->stack_a, i);
	while (ctx->stack_a.values[i] != ctx->stack_a.capacity)
	{
		val = ctx->stack_a.values[i];
		i = get_next_bottom_idx(&ctx->stack_a, i);
		if (ctx->stack_a.values[i] != val + 1)
			return (false);
	}
	return (true);
}

static void	sort_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}

static bool	are_vals_consec(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	reduce_max_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_stack	*a;

	a = &ctx->stack_a;
	if (seg->loc == LOCATION_TOP_A && seg->count == 3
		&& are_vals_consec(value_at(a, 1), value_at(a, 2), value_at(a, 3),
			value_at(a, 4)) && is_stack_a_part_sorted(ctx, 4))
	{
		sort_three_elements_segment(ctx, seg);
		return ;
	}
	if (seg->loc == LOCATION_TOP_A && value_at(a, 1) == value_at(a, 3) - 1
		&& is_stack_a_part_sorted(ctx, 3))
	{
		swap_a(ctx);
		seg->count--;
	}
	if (seg->loc == LOCATION_TOP_A && is_stack_a_part_sorted(ctx, 1))
		seg->count--;
}
