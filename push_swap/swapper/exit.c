/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:43:04 by alebedev        #+#    #+#             */
/*   Updated: 2025/06/17 15:37:16 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_context(t_context *ctx)
{
	if (ctx->stack_a.values)
		free(ctx->stack_a.values);
	if (ctx->stack_b.values)
		free(ctx->stack_b.values);
}

void	handle_error(t_context *ctx)
{
	free_context(ctx);
	exit(EXIT_FAILURE);
}
