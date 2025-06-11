/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +/-+   */
/*   Created: 2025/06/17 15:30:00 by alebedev        #    #    #             */
/*   Updated: 2025/06/17 15:38:16 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_context	ctx;

	if (argc < 2)
		return (1);
	init_context(&ctx, argc, argv);
	apply_operations(&ctx);
	print_stack(&ctx.stack_a);
	free_context(&ctx);
	return (0);
}
