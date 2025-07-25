/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:49:25 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/09 14:04:03 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_stack_size(t_stack *stack)
{
	if (stack->newest_idx == stack->oldest_idx
		&& stack->values[stack->newest_idx] == 0)
		return (0);
	if (stack->newest_idx > stack->oldest_idx)
		return ((stack->capacity - stack->newest_idx) + (stack->oldest_idx
				+ 1));
	else
		return (stack->oldest_idx - stack->newest_idx + 1);
}

int	get_next_bottom_idx(t_stack *stack, int current_idx)
{
	if (get_stack_size(stack) == 0)
		return (current_idx);
	if (current_idx == stack->capacity - 1)
		return (0);
	return (current_idx + 1);
}

int	get_next_top_idx(t_stack *stack, int current_idx)
{
	if (get_stack_size(stack) == 0)
		return (current_idx);
	if (current_idx == 0)
		return (stack->capacity - 1);
	return (current_idx - 1);
}

bool	is_stack_full(t_stack *stack)
{
	return (stack->capacity == get_stack_size(stack));
}

int	value_at(t_stack *stack, int pos)
{
	int	idx;

	idx = stack->newest_idx;
	while (--pos > 0)
		idx = get_next_bottom_idx(stack, idx);
	return (stack->values[idx]);
}
