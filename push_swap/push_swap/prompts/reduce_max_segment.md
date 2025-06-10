I don't understand how this function works.

```c
void	reduce_max_segment(t_context *ctx, t_stack_segmnt *seg)
{
	t_stack	*a;

	a = &ctx->stack_a;
	if (seg->loc == LOCATION_TOP_A && seg->count == 3
		&& are_vals_consec(value_at(a, 1), value_at(a, 2), value_at(a, 3),
			value_at(a, 4)) && is_stack_a_part_sorted(ctx, 4))
	{
		sort_three_elements_segment(ctx, seg);
		return ;
	}
	if (seg->loc == LOCATION_TOP_A && value_at(a, 1) == value_at(a, 3) - 1
		&& is_stack_a_part_sorted(ctx, 3))
	{
		swap_a(ctx);
		seg->count--;
	}
	if (seg->loc == LOCATION_TOP_A && is_stack_a_part_sorted(ctx, 1))
		seg->count--;
}
```

Also, in split_segment, if `(next_val > max_val - pivot_large)` we move the element to max split and:

```c
			reduce_max_segment(ctx, &split->max);
			if (is_stack_a_part_sorted(ctx, 1) && seg->count)
				sort_small_segment(ctx, seg);
```

why do we do reduce_max_segment and the check to sort_small_segment? What does reduce_max_segment do and the check check for?
