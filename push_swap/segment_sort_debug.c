/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:53:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 13:12:42 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void		print_stack(t_stack *stack);

static void	sort_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_segmnt_split	split;

	printf("Started sort_segment ################\n");
	approach_seg_from_top(ctx, seg);
	place_elements(ctx, seg);
	if (seg->count <= 3)
	{
		if (seg->count == 3)
			place_three_elements(ctx, seg);
		else if (seg->count == 2)
			place_two_elements(ctx, seg);
		else if (seg->count == 1)
			place_one_element(ctx, seg);
		printf("-> returned early from sort_segment:\n");
		print_stack(&ctx->stack_a);
		print_stack(&ctx->stack_b);
		return ;
	}
	split_segment(ctx, seg, &split);
	printf("splitting done (!!!)\n");
	sort_segment(ctx, &split.max);
	printf("> returned from sort_segment(max):\n");
	print_stack(&ctx->stack_a);
	print_stack(&ctx->stack_b);
	sort_segment(ctx, &split.mid);
	printf("> returned from sort_segment(mid):\n");
	print_stack(&ctx->stack_a);
	print_stack(&ctx->stack_b);
	sort_segment(ctx, &split.min);
	printf("> returned from sort_segment(min):\n");
	print_stack(&ctx->stack_a);
	print_stack(&ctx->stack_b);
	printf("Split and called sort_segment with subsegments\n");
	printf("\n");
}

void	recursive_segment_sort(t_context *ctx)
{
	t_stack_segmnt	seg;

	seg.loc = LOCATION_TOP_A;
	seg.count = ctx->stack_a.capacity;
	sort_segment(ctx, &seg);
}
