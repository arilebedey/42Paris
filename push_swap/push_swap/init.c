/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:13:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/19 23:23:29 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	check_duplicates(t_context *ctx, int *values, int count,
		char **args)
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
				if (ctx->args_allocated)
					free_args(args);
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
		{
			free(raw_nums);
			if (ctx->args_allocated)
				free_args(args);
			handle_error(ctx);
		}
		raw_nums[i] = ft_atoi(args[i]);
		i++;
	}
	check_duplicates(ctx, raw_nums, count, args);
	convert_to_ranks(raw_nums, stack->values, count);
	stack->oldest_idx = count - 1;
	free(raw_nums);
}

void	init_context(t_context *ctx, int argc, char **argv)
{
	char	**args;

	if ((argc == 2 && argv[1][0] == '\0') || argc < 2)
		early_error();
	ctx->op_hist = NULL;
	ctx->stack_a.values = NULL;
	ctx->stack_b.values = NULL;
	args = parse_args(&argc, argv);
	ctx->args_allocated = (args != argv + 1);
	init_stack(ctx, &ctx->stack_a, argc - 1);
	init_stack(ctx, &ctx->stack_b, argc - 1);
	fill_stack(ctx, &ctx->stack_a, argc - 1, args);
	if (args != argv + 1)
		free_args(args);
}
