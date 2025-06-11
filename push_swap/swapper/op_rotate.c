/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:09:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 15:37:47 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate(t_stack *stack)
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
	rotate(&ctx->stack_a);
}

void	rotate_b(t_context *ctx)
{
	rotate(&ctx->stack_b);
}

void	rotate_ab(t_context *ctx)
{
	rotate(&ctx->stack_a);
	rotate(&ctx->stack_b);
}
