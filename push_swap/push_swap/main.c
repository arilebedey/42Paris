/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:49:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/11 13:26:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char *argv[])
{
	t_context	ctx;

	init_context(&ctx, argc, argv);
	sort(&ctx);
	print_operations(ctx.op_hist);
	free_context(&ctx);
}
