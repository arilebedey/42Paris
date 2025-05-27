/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:57:45 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/27 12:11:34 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;
	int	next_idx;

	if (get_stack_size(stack) < 2)
		return ;
	next_idx = get_next_bottom_idx(stack, stack->newest_idx);
	tmp = stack->values[next_idx];
	stack->values[next_idx] = stack->values[stack->newest_idx];
	stack->values[stack->newest_idx] = tmp;
}

void	swap_b(t_context *ctx)
{
	swap(&ctx->stack_b);
	record_op(ctx, sb);
}

void	swap_a(t_context *ctx)
{
	swap(&ctx->stack_a);
	record_op(ctx, sa);
}

void	swap_ab(t_context *ctx)
{
	swap(&ctx->stack_a);
	swap(&ctx->stack_b);
	record_op(ctx, ss);
}
