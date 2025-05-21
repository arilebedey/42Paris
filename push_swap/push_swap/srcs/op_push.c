/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:49:33 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/21 16:49:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	int	dst_idx;

	if (get_stack_size(dst) == dst->capacity)
		return ;
	dst_idx = get_next_top_idx(src, dst->newest_idx);
}
