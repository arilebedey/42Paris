/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:34:23 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 13:29:54 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	for (int i = 0; i < stack->capacity; i++)
		printf("%d ", stack->values[i]);
	printf("newest_idx: %d oldest_idx: %d\n", stack->newest_idx,
		stack->oldest_idx);
}
