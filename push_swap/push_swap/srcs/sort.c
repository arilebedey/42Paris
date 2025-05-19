#include "../includes/push_swap.h"

static bool	is_sorted(t_context *ctx)
{
	int	i;
	int	expected_rank;

	i = ctx->stack_a.newest_idx;
	expected_rank = 1;
	while (expected_rank <= ctx->stack_a.capacity)
	{
		if (ctx->stack_a.values[i] != expected_rank)
			return (false);
		expected_rank++;
		i = get_next_bottom_idx(&ctx->stack_a, i);
	}
	return (true);
}

void	sort(t_context *ctx)
{
	if (ctx->stack_a.capacity <= 1 || is_sorted(ctx))
		return;
	if (ctx->stack_a.capacity == 3)
		sort_three_elements(ctx);
	if (ctx->stack_a.capacity == 5)
		sort_five_elements(ctx);
	else
		recuresive_segment_sort(ctx);
	optimize_operations(ctx);
}
