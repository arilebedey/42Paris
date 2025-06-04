/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_segment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:12:27 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/04 16:40:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_split_sizes(t_stack_segmnt *min, t_stack_segmnt *mid,
		t_stack_segmnt *max)
{
	min->count = 0;
	mid->count = 0;
	max->count = 0;
}

static void	set_split_locations(t_stack_location src_loc, t_stack_segmnt *min,
		t_stack_segmnt *mid, t_stack_segmnt *max)
{
	if (src_loc == LOCATION_TOP_A)
	{
		min->loc = LOCATION_BOTTOM_B;
		mid->loc = LOCATION_TOP_B;
		max->loc = LOCATION_BOTTOM_A;
	}
	if (src_loc == LOCATION_BOTTOM_A)
	{
		min->loc = LOCATION_BOTTOM_B;
		mid->loc = LOCATION_TOP_B;
		max->loc = LOCATION_TOP_A;
	}
	if (src_loc == LOCATION_TOP_B)
	{
		min->loc = LOCATION_BOTTOM_B;
		mid->loc = LOCATION_BOTTOM_A;
		max->loc = LOCATION_TOP_A;
	}
	if (src_loc == LOCATION_BOTTOM_B)
	{
		min->loc = LOCATION_TOP_B;
		mid->loc = LOCATION_BOTTOM_A;
		max->loc = LOCATION_TOP_A;
	}
}

static void	set_pivot_values(t_stack_location loc, int seg_size,
		int *pivot_small, int *pivot_large)
{
	*pivot_large = seg_size / 3;
	if (loc == LOCATION_TOP_A || loc == LOCATION_BOTTOM_A)
		*pivot_small = 2 * (seg_size / 3);
	if (loc == LOCATION_TOP_B || loc == LOCATION_BOTTOM_B)
		*pivot_small = seg_size / 2;
	if ((loc == LOCATION_TOP_A || loc == LOCATION_BOTTOM_A) && seg_size < 15)
		*pivot_small = seg_size;
	if (loc == LOCATION_BOTTOM_B && seg_size < 8)
		*pivot_large = seg_size / 2;
}

void	split_segment(t_context *ctx, t_stack_segmnt *seg,
		t_segmnt_split *split)
{
	int	pivot_small;
	int	pivot_large;
	int	max_val;
	int	next_val;

	init_split_sizes(&split->min, &split->mid, &split->max);
	set_split_locations(seg->loc, &split->min, &split->mid, &split->max);
	set_pivot_values(seg->loc, seg->count, &pivot_small, &pivot_large);
	max_val = segment_max_value(ctx, seg);
	while (seg->count--)
	{
		next_val = segment_value(ctx, seg, 1);
		if (next_val > max_val - pivot_large)
		{
			split->max.count += move_to_loc(ctx, seg->loc, split->max.loc);
			reduce_max_segment(ctx, &split->max);
			if (is_stack_a_part_sorted(ctx, 1) && seg->count)
				sort_small_segment(ctx, seg);
		}
		else if (next_val > max_val - pivot_small)
			split->mid.count += move_to_loc(ctx, seg->loc, split->mid.loc);
		else
			split->min.count += move_to_loc(ctx, seg->loc, split->min.loc);
	}
}
