/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:13:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/10 17:10:23 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_duplicates(t_context *ctx, int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
			{
				free(values);
				handle_error(ctx);
			}
			j++;
		}
		i++;
	}
}

static void	convert_to_ranks(int *raw_nums, int *ranks, int count)
{
	int	i;
	int	j;
	int	smaller_count;

	i = 0;
	while (i < count)
	{
		j = 0;
		smaller_count = 0;
		while (j < count)
		{
			if (raw_nums[j] <= raw_nums[i])
				smaller_count++;
			j++;
		}
		ranks[i] = smaller_count;
		i++;
	}
}

static void	init_stack(t_context *ctx, t_stack *stack, int capacity)
{
	stack->values = malloc(sizeof(int) * capacity);
	if (!stack->values)
		handle_error(ctx);
	stack->newest_idx = 0;
	stack->oldest_idx = 0;
	stack->capacity = capacity;
	ft_memset(stack->values, 0, sizeof(int) * capacity);
}

static void	fill_stack(t_context *ctx, t_stack *stack, int count, char **args)
{
	int	*raw_nums;
	int	i;

	raw_nums = malloc(sizeof(int) * count);
	if (!raw_nums)
		handle_error(ctx);
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			handle_error(ctx);
		raw_nums[i] = ft_atoi(args[i]);
		i++;
	}
	check_duplicates(ctx, raw_nums, count);
	convert_to_ranks(raw_nums, stack->values, count);
	stack->oldest_idx = count - 1;
	free(raw_nums);
}

void	init_context(t_context *ctx, int argc, char **argv)
{
	--argc;
	ctx->op_hist = NULL;
	init_stack(ctx, &ctx->stack_a, argc);
	init_stack(ctx, &ctx->stack_b, argc);
	fill_stack(ctx, &ctx->stack_a, argc, ++argv);
}
