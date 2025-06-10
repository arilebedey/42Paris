/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:43:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/10 17:10:42 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_context(t_context *ctx)
{
	if (ctx->stack_a.values)
		free(ctx->stack_a.values);
	if (ctx->stack_b.values)
		free(ctx->stack_b.values);
	if (ctx->op_hist)
		clear_list(&ctx->op_hist);
}

void	handle_error(t_context *ctx)
{
	free_context(ctx);
	ft_putendl_fd("Error", 2);
	// WARN: What does this do?
	exit(EXIT_FAILURE);
}
