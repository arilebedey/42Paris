/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:43:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/11 13:26:48 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_context(t_context *ctx)
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
	exit(EXIT_FAILURE);
}
