/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:09:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 15:39:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	r_rotate(t_stack *stack)
{
	if (!stack || get_stack_size(stack) == 0)
		return ;
	if (is_stack_full(stack))
	{
		stack->newest_idx = stack->oldest_idx;
		stack->oldest_idx = get_next_top_idx(stack, stack->oldest_idx);
	}
	else
	{
		stack->newest_idx = get_next_top_idx(stack, stack->newest_idx);
		stack->values[stack->newest_idx] = stack->values[stack->oldest_idx];
		stack->values[stack->oldest_idx] = 0;
		stack->oldest_idx = get_next_top_idx(stack, stack->oldest_idx);
	}
}

void	r_rotate_a(t_context *ctx)
{
	r_rotate(&ctx->stack_a);
}

void	r_rotate_b(t_context *ctx)
{
	r_rotate(&ctx->stack_b);
}

void	r_rotate_ab(t_context *ctx)
{
	r_rotate(&ctx->stack_a);
	r_rotate(&ctx->stack_b);
}
