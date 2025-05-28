/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:56:28 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/28 14:49:11 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	is_sorted(t_context *ctx)
{
	int	i;
	int	expected_rank;

	i = ctx->stack_a.newest_idx;
	expected_rank = 1;
	while (expected_rank <= ctx->stack_a.capacity)
	{
		if (ctx->stack_a.values[i] != expected_rank)
			return (false);
		expected_rank++;
		i = get_next_bottom_idx(&ctx->stack_a, i);
	}
	return (true);
}

static void	sort_three_elements(t_context *ctx)
{
	int	first;
	int	second;
	int	third;

	first = get_value_at(&ctx->stack_a, 1);
	second = get_value_at(&ctx->stack_a, 2);
	third = get_value_at(&ctx->stack_a, 3);
	if (first > second && third > second && third > first)
		swap_a(ctx);
	else if (first > second && first > third && third > second)
		rotate_a(ctx);
	else if (second > first && first > third && second > third)
		r_rotate_a(ctx);
	else if (second > third && third > first && second > first)
	{
		swap_a(ctx);
		rotate_a(ctx);
	}
	else if (first > third && first > second && second > third)
	{
		swap_a(ctx);
		r_rotate_a(ctx);
	}
}

static void	sort_five_elements(t_context *ctx)
{
	int	top_a;

	while (get_stack_size(&ctx->stack_a) > 3)
	{
		top_a = get_value_at(&ctx->stack_a, 1);
		if (top_a == 1 || top_a == 2)
			push_b(ctx);
		else
			rotate_a(ctx);
	}
	if (get_value_at(&ctx->stack_b, 1) < get_value_at(&ctx->stack_b, 2))
		swap_b(ctx);
	sort_three_elements(ctx);
	push_a(ctx);
	push_a(ctx);
}

void	sort(t_context *ctx)
{
	if (ctx->stack_a.capacity <= 1 || is_sorted(ctx))
		return ;
	if (ctx->stack_a.capacity == 3)
		sort_three_elements(ctx);
	if (ctx->stack_a.capacity == 5)
		sort_five_elements(ctx);
	else
		recursive_segment_sort(ctx);
	optimize_operations(ctx);
}
