/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:43:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/18 14:47:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdlib.h>

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_context(t_context *ctx)
{
	if (ctx->stack_a.values)
		free(ctx->stack_a.values);
	if (ctx->stack_b.values)
		free(ctx->stack_b.values);
	if (ctx->op_hist)
		clear_list(&ctx->op_hist);
}

void	early_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	handle_error(t_context *ctx)
{
	free_context(ctx);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	handle_exit(t_context *ctx)
{
	free_context(ctx);
	exit(EXIT_SUCCESS);
}
