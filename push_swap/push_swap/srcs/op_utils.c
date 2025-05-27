/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:54:44 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/27 11:07:28 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	record_op(t_context *ctx, t_ops op)
{
	t_opnode	*node;

	node = new_opnode((void *)(uintptr_t)op);
	if (!node)
		handle_error(ctx);
	add_opnode_back(&ctx->op_hist, node);
}
