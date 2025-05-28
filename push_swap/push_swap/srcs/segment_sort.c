/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:53:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/28 14:05:06 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	recursive_segment_sort(t_context *ctx)
{
	t_stack_segmnt	seg;

	seg.location = LOCATION_TOP_A;
	seg.elem_count = ctx->stack_a.capacity;
	sort_segment(ctx, &seg);
}
