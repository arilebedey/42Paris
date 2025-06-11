/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:46:51 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/17 15:46:51 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    :::      :::    :::   */
/*   By: alebedev <alebedev@student.42.fr>          ###   #fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static void	execute_operation(t_context *ctx, const char *op)
{
	if (strcmp(op, "pa") == 0)
		push_a(ctx);
	else if (strcmp(op, "pb") == 0)
		push_b(ctx);
	else if (strcmp(op, "sa") == 0)
		swap_a(ctx);
	else if (strcmp(op, "sb") == 0)
		swap_b(ctx);
	else if (strcmp(op, "ss") == 0)
		swap_ab(ctx);
	else if (strcmp(op, "ra") == 0)
		rotate_a(ctx);
	else if (strcmp(op, "rb") == 0)
		rotate_b(ctx);
	else if (strcmp(op, "rr") == 0)
		rotate_ab(ctx);
	else if (strcmp(op, "rra") == 0)
		r_rotate_a(ctx);
	else if (strcmp(op, "rrb") == 0)
		r_rotate_b(ctx);
	else if (strcmp(op, "rrr") == 0)
		r_rotate_ab(ctx);
	else
		handle_error(ctx);
}

static bool	is_stack_sorted(t_stack *stack)
{
	int	size;
	int	idx;
	int	prev_value;
	int	i;

	size = get_stack_size(stack);
	idx = stack->newest_idx;
	if (size <= 1)
		return (true);
	prev_value = stack->values[idx];
	idx = get_next_bottom_idx(stack, idx);
	for (i = 1; i < size; i++)
	{
		if (stack->values[idx] < prev_value)
			return (false);
		prev_value = stack->values[idx];
		idx = get_next_bottom_idx(stack, idx);
	}
	return (true);
}

void	apply_operations(t_context *ctx)
{
	char	buffer[5];
	int		i;
	char	c;

	i = 0;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == '\n')
		{
			buffer[i] = '\0';
			if (i > 0)
				execute_operation(ctx, buffer);
			i = 0;
		}
		else if (i < 4)
			buffer[i++] = c;
		else
			handle_error(ctx);
	}
	print_stack(&ctx->stack_a);
	if (is_stack_sorted(&ctx->stack_a) && get_stack_size(&ctx->stack_b) == 0)
		printf("Stack is sorted\n");
	else
		printf("Stack is not sorted\n");
}

void	print_stack(t_stack *stack)
{
	int	size;
	int	idx;
	int	i;

	size = get_stack_size(stack);
	idx = stack->newest_idx;
	for (i = 0; i < size; i++)
	{
		printf("%d", stack->values[idx]);
		idx = get_next_bottom_idx(stack, idx);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}
