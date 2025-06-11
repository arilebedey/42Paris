/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:49:33 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 15:37:34 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	int	dst_idx;

	if (is_stack_full(dst))
		return ;
	dst_idx = get_next_top_idx(dst, dst->newest_idx);
	dst->values[dst_idx] = src->values[src->newest_idx];
	dst->newest_idx = dst_idx;
	src->values[src->newest_idx] = 0;
	src->newest_idx = get_next_bottom_idx(src, src->newest_idx);
}

void	push_a(t_context *ctx)
{
	push(&ctx->stack_b, &ctx->stack_a);
}

void	push_b(t_context *ctx)
{
	push(&ctx->stack_a, &ctx->stack_b);
}
