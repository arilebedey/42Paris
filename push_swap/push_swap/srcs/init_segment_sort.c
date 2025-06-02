/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_segment_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:53:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/02 15:21:11 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_segmnt_split	split;

	move_segment_to_top(ctx, seg);
	sort_small_segment(ctx, seg);
	if (seg->elem_count <= 3)
	{
		if (seg->elem_count == 3)
			sort_three_elements_segment(ctx, seg);
		else if (seg->elem_count == 2)
			sort_two_elements(ctx, seg);
		else if (seg->elem_count == 1)
			sort_one_element(ctx, seg);
		return ;
	}
	split_segment(ctx, seg, &split);
	sort_segment(ctx, &split.max_values);
	sort_segment(ctx, &split.mid_values);
	sort_segment(ctx, &split.min_values);
}

void	recursive_segment_sort(t_context *ctx)
{
	t_stack_segmnt	seg;

	seg.location = LOCATION_TOP_A;
	seg.elem_count = ctx->stack_a.capacity;
	sort_segment(ctx, &seg);
}
