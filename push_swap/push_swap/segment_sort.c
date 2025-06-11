/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:53:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 13:37:20 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void		print_stack(t_stack *stack);

static void	sort_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_segmnt_split	split;

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
		return ;
	}
	split_segment(ctx, seg, &split);
	sort_segment(ctx, &split.max);
	sort_segment(ctx, &split.mid);
	sort_segment(ctx, &split.min);
}

void	recursive_segment_sort(t_context *ctx)
{
	t_stack_segmnt	seg;

	seg.loc = LOCATION_TOP_A;
	seg.count = ctx->stack_a.capacity;
	sort_segment(ctx, &seg);
}
