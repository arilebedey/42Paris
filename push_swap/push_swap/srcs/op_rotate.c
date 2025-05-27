/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:09:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/27 16:39:43 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_stack *stack)
{
	if (!stack || get_stack_size(stack) == 0)
		return ;
	if (is_stack_full(stack))
	{
		stack->oldest_idx = stack->newest_idx;
		stack->newest_idx = get_next_bottom_idx(stack, stack->newest_idx);
	}
	else
	{
		stack->oldest_idx = get_next_bottom_idx(stack, stack->oldest_idx);
		stack->values[stack->oldest_idx] = stack->values[stack->newest_idx];
		stack->values[stack->newest_idx] = 0;
		stack->newest_idx = get_next_bottom_idx(stack, stack->newest_idx);
	}
}

void	rotate_a(t_context *ctx)
{
	r_rotate(&ctx->stack_a);
	record_op(ctx, ra);
}

void	rotate_b(t_context *ctx)
{
	r_rotate(&ctx->stack_b);
	record_op(ctx, rb);
}

void	rotate_ab(t_context *ctx)
{
	r_rotate(&ctx->stack_a);
	r_rotate(&ctx->stack_b);
	record_op(ctx, rr);
}
