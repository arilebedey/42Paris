#### src/stack/stack_utils.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:14 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 22:00:33 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	next_up(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
		return (index);
	if (index == 0)
		return (stk->size - 1);
	else
		return (index - 1);
}

int	next_down(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
		return (index);
	if (index == stk->size - 1)
		return (0);
	else
		return (index + 1);
}

int	value(t_stack *stk, int n)
{
	int	i;

	i = stk->top;
	while (--n > 0)
		i = next_down(stk, i);
	return (stk->stack[i]);
}

int	current_size(t_stack *stk)
{
	if (stk->top == stk->bottom && stk->stack[stk->top] == 0)
		return (0);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + (stk->bottom + 1));
	else
		return (stk->bottom - stk->top + 1);
}

bool	is_full(t_stack *stk)
{
	return (stk->size == current_size(stk));
}
```

#### src/stack/stack_init.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:08 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 18:44:51 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_stack(t_ps *data, t_stack *stk, int size, char **arg)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		error(data);
	i = 0;
	while (arg[i])
	{
		if (!valid_arg(arg[i]))
			error(data);
		numbers[i] = ft_atoi(arg[i]);
		i++;
	}
	check_duplication(data, numbers, size);
	random_to_rank(numbers, stk->stack, size);
	stk->bottom = size - 1;
	free(numbers);
}

bool	valid_arg(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*arg == '\0')
		return (false);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (*arg == '\0')
			return (false);
	}
	num = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = num * 10 + (*arg - '0');
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		arg++;
	}
	return (true);
}

void	check_duplication(t_ps *data, int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data);
			}
			j++;
		}
		i++;
	}
}

void	random_to_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				count_smaller++;
		rank[i] = count_smaller;
		i++;
	}
}
```

#### src/stack/op_utils.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:02 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:04:33 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	save_op(t_ps *data, t_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->op_list, new);
}

void	print_operations(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_printf("%s\n", op_to_string(op_from(reader)));
		reader = reader->next;
	}
}

const char	*op_to_string(t_op op)
{
	static const char	*strings[12];

	strings[0] = "null_op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[op]);
}

t_op	op_from(t_list *node)
{
	return ((t_op)(uintptr_t)node->content);
}
```

#### src/stack/op_swap.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:57 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:09:00 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = tmp;
}

void	swap_a(t_ps *data)
{
	swap(&data->a);
	if (data->writing_mode)
		save_op(data, sa);
}

void	swap_b(t_ps *data)
{
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, sb);
}

void	swap_ab(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, ss);
}
```

#### src/stack/op_rotate.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:52 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:17:29 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->stack[stk->bottom] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}

void	rotate_a(t_ps *data)
{
	rotate(&data->a);
	if (data->writing_mode)
		save_op(data, ra);
}

void	rotate_b(t_ps *data)
{
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rb);
}

void	rotate_ab(t_ps *data)
{
	rotate(&data->a);
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rr);
}
```

#### src/stack/op_reverse_rotate.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:47 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:08:50 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	r_rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

void	r_rotate_a(t_ps *data)
{
	r_rotate(&data->a);
	if (data->writing_mode)
		save_op(data, rra);
}

void	r_rotate_b(t_ps *data)
{
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrb);
}

void	r_rotate_ab(t_ps *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrr);
}
```

#### src/stack/op_push.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:41 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:08:44 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (is_full(dest))
		return ;
	dest_i = next_up(dest, dest->top);
	dest->stack[dest_i] = src->stack[src->top];
	dest->top = dest_i;
	src->stack[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_ps *data)
{
	push(&data->b, &data->a);
	if (data->writing_mode)
		save_op(data, pa);
}

void	push_b(t_ps *data)
{
	push(&data->a, &data->b);
	if (data->writing_mode)
		save_op(data, pb);
}
```

#### src/stack/data_mngt.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mngt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:35 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 23:17:40 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_data(t_ps *data, int argc, char **argv, bool writing_mode)
{
	--argc;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, ++argv);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}

void	init_stack(t_ps *data, t_stack *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->top = 0;
	stk->bottom = 0;
	stk->size = size;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

bool	is_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.stack[i] != rank)
			return (false);
		rank++;
		i = next_down(&data->a, i);
	}
	return (true);
}

void	error(t_ps *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_data(t_ps *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}
```

#### src/push_swap/sort.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:28 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/30 18:22:12 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *data)
{
	if (data->a.size <= 1 || is_sorted(data))
		return ;
	else if (data->a.size == 3)
		sort_three_a(data);
	else if (data->a.size == 5)
		sort_five_a(data);
	else
		chunk_sort(data);
	post_sort_optimization(data);
}

void	sort_three_a(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	first = value(&data->a, 1);
	second = value(&data->a, 2);
	third = value(&data->a, 3);
	if (first > second && third > second && third > first)
		swap_a(data);
	else if (first > second && third > second && first > third)
		rotate_a(data);
	else if (second > first && second > third && first > third)
		r_rotate_a(data);
	else if (second > first && second > third && third > first)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first > second && second > third && first > third)
	{
		swap_a(data);
		r_rotate_a(data);
	}
}

void	sort_five_a(t_ps *data)
{
	while (current_size(&data->a) > 3)
	{
		if (value(&data->a, 1) == 1 || value(&data->a, 1) == 2)
			push_b(data);
		else
			rotate_a(data);
	}
	if (value(&data->b, 1) < value(&data->b, 2))
		swap_b(data);
	sort_three_a(data);
	push_a(data);
	push_a(data);
}
```

#### src/push_swap/opti_to_the_top.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_to_the_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:20 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 18:45:14 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&data->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&data->a) == to_sort->size)
		to_sort->loc = TOP_A;
}
```

#### src/push_swap/opti_sort_three.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:16 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 17:33:43 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *data, t_chunk *to_sort)
{
	t_stack	*stk;
	int		max;

	stk = loc_to_stack(data, to_sort->loc);
	max = chunk_max_value(data, to_sort);
	if (to_sort->loc == TOP_A)
		sort_three_top_a(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, stk, max);
	else if (to_sort->loc == TOP_B)
		sort_three_top_b(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, stk, max);
}

void	sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	push_a(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
		push_a(data);
	push_a(data);
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	r_rotate_a(data);
	r_rotate_a(data);
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		r_rotate_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
		r_rotate_a(data);
	else
	{
		push_b(data);
		r_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	r_rotate_b(data);
	r_rotate_b(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		r_rotate_b(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		r_rotate_b(data);
	}
	else
	{
		r_rotate_b(data);
		push_a(data);
	}
	to_sort->loc = TOP_B;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}
```

#### src/push_swap/opti_sort_asap.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_asap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:30 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 23:12:37 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_max_reduction(t_ps *data, t_chunk *max)
{
	t_stack	*a;

	a = &data->a;
	if (max->loc == TOP_A && max->size == 3 && is_consecutive(value(a, 1),
			value(a, 2), value(a, 3), value(a, 4)) && a_partly_sort(data, 4))
	{
		sort_three(data, max);
		return ;
	}
	if (max->loc == TOP_A && value(a, 1) == value(a, 3) - 1
		&& a_partly_sort(data, 3))
	{
		swap_a(data);
		max->size--;
	}
	if (max->loc == TOP_A && a_partly_sort(data, 1))
		max->size--;
}

bool	a_partly_sort(t_ps *data, int from)
{
	int		i;
	t_stack	*a;
	int		value;

	a = &data->a;
	i = a->top;
	while (--from)
		i = next_down(a, i);
	while (a->stack[i] != data->a.size)
	{
		value = a->stack[i];
		i = next_down(a, i);
		if (a->stack[i] != value + 1)
			return (false);
	}
	return (true);
}

bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	sort_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}
```

#### src/push_swap/opti_post_sort_utils.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_post_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:15:00 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:04:33 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	neutral_op(t_op op)
{
	if (op == pa)
		return (pb);
	if (op == pb)
		return (pa);
	if (op == ra)
		return (rra);
	if (op == rb)
		return (rrb);
	if (op == rra)
		return (ra);
	if (op == rrb)
		return (rb);
	if (op == sa)
		return (sa);
	if (op == sb)
		return (sb);
	if (op == rr)
		return (rrr);
	return (null_op);
}

bool	op_on_same_stack(t_op ref, t_op to_check)
{
	if (ref == pa || ref == pb || ref == rr || ref == rrr)
		return (true);
	if (to_check == pa || to_check == pb || to_check == rr || to_check == rrr)
		return (true);
	else if (ref == ra || ref == rra || ref == sa)
		return (to_check == ra || to_check == rra || to_check == sa);
	else if (ref == rb || ref == rrb || ref == sb)
		return (to_check == rb || to_check == rrb || to_check == sb);
	return (false);
}

t_op	child_op(t_op first, t_op second)
{
	if ((first == ra && second == rb) || (first == rb && second == ra))
		return (rr);
	else if ((first == rra && second == rrb) || (first == rrb && second == rra))
		return (rrr);
	else if ((first == sa && second == sb) || (first == sb && second == sa))
		return (ss);
	else
		return (null_op);
}

void	remove_op(t_list *to_delete)
{
	to_delete->prev->next = to_delete->next;
	if (to_delete->next)
		to_delete->next->prev = to_delete->prev;
	ft_lstdelone(to_delete, NULL);
}
```

#### src/push_swap/opti_post_sort.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_post_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:19 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:04:33 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	post_sort_optimization(t_ps *data)
{
	if (!data->op_list)
		return ;
	eliminate_neutral_op(data->op_list);
	merge_op(data->op_list);
}

void	eliminate_neutral_op(t_list *op_list)
{
	t_list	*ref;
	t_list	*cmp;
	t_op	op_neutral;

	ref = op_list->next;
	while (ref && ref->next)
	{
		op_neutral = neutral_op(op_from(ref));
		if (op_neutral)
		{
			cmp = ref->next;
			while (!op_on_same_stack(op_from(ref), op_from(cmp))
				&& op_from(cmp) != op_neutral && cmp->next)
				cmp = cmp->next;
			if (ref->prev && op_from(cmp) == op_neutral)
			{
				ref = ref->prev;
				remove_op(ref->next);
				remove_op(cmp);
				continue ;
			}
		}
		ref = ref->next;
	}
}

void	merge_op(t_list *op_list)
{
	t_list	*reader;
	t_op	child;

	reader = op_list;
	while (reader && reader->next)
	{
		child = child_op(op_from(reader), op_from(reader->next));
		if (child)
		{
			remove_op(reader->next);
			reader->content = (void *)(uintptr_t)child;
		}
		reader = reader->next;
	}
}
```

#### src/push_swap/opti_easy_sort.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_easy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:15 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/28 23:13:09 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_ps *data, t_chunk *to_sort)
{
	while (to_sort->loc != TOP_A && to_sort->size)
	{
		if (value(&data->a, 1) == chunk_value(data, to_sort, 1) + 1
			&& to_sort->size > 0)
			sort_one(data, to_sort);
		else if (value(&data->a, 1) == chunk_value(data, to_sort, 2) + 1
			&& to_sort->size > 1)
			easy_sort_second(data, to_sort);
		else
			break ;
	}
}

void	easy_sort_second(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == TOP_B)
		handle_top_b(data, to_sort);
	else if (to_sort->loc == BOTTOM_A)
		handle_bottom_a(data, to_sort);
	else if (to_sort->loc == BOTTOM_B)
		handle_bottom_b(data, to_sort);
	to_sort->size--;
}

void	handle_top_b(t_ps *data, t_chunk *to_sort)
{
	swap_b(data);
	push_a(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
}

void	handle_bottom_a(t_ps *data, t_chunk *to_sort)
{
	r_rotate_a(data);
	r_rotate_a(data);
	swap_a(data);
	if (value(&data->a, 1) == value(&data->a, 2) - 1)
		to_sort->size--;
	else
		rotate_a(data);
}

void	handle_bottom_b(t_ps *data, t_chunk *to_sort)
{
	r_rotate_b(data);
	r_rotate_b(data);
	push_a(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
	else
		rotate_b(data);
}
```

#### src/push_swap/move.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:08 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:14 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_to(t_ps *data, t_loc from, t_loc to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}

void	move_from_top_a(t_ps *data, t_loc to)
{
	if (to == TOP_B)
		push_b(data);
	else if (to == BOTTOM_A)
		rotate_a(data);
	else if (to == BOTTOM_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_ps *data, t_loc to)
{
	if (to == TOP_A)
		push_a(data);
	else if (to == BOTTOM_B)
		rotate_b(data);
	else if (to == BOTTOM_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_ps *data, t_loc to)
{
	if (to == TOP_A)
		r_rotate_a(data);
	else if (to == TOP_B)
	{
		r_rotate_a(data);
		push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		r_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_ps *data, t_loc to)
{
	if (to == TOP_B)
		r_rotate_b(data);
	else if (to == TOP_A)
	{
		r_rotate_b(data);
		push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		r_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
```

#### src/push_swap/main.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:08:24 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/27 21:08:26 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	data;

	init_data(&data, argc, argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
```

#### src/push_swap/chunk_utils.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:02 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:14 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_value(t_ps *data, t_chunk *chunk, int n)
{
	t_loc	loc;
	t_stack	*stk;
	int		i;

	loc = chunk->loc;
	stk = loc_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = stk->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stk->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(stk, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(stk, i);
	return (stk->stack[i]);
}

int	chunk_max_value(t_ps *data, t_chunk *chunk)
{
	t_stack	*stk;
	int		size;
	int		max_value;
	int		i;

	stk = loc_to_stack(data, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stk->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = stk->bottom;
	while (size--)
	{
		if (stk->stack[i] > max_value)
			max_value = stk->stack[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(stk, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(stk, i);
	}
	return (max_value);
}

t_stack	*loc_to_stack(t_ps *data, t_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}
```

#### src/push_swap/chunk_split.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:57:19 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:14 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_split(t_ps *data, t_chunk *to_split, t_split_dest *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	innit_size(&dest->min, &dest->mid, &dest->max);
	set_split_loc(to_split->loc, &dest->min, &dest->mid, &dest->max);
	set_third_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(data, to_split);
	while (to_split->size--)
	{
		next_value = chunk_value(data, to_split, 1);
		if (next_value > max_value - pivot_2)
		{
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
			split_max_reduction(data, &dest->max);
			if (a_partly_sort(data, 1) && to_split->size)
				easy_sort(data, to_split);
		}
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
	}
}

void	innit_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

void	set_third_pivots(t_loc loc, int crt_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = 2 * crt_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = crt_size / 2;
	if ((loc == TOP_A || loc == BOTTOM_A) && crt_size < 15)
		*pivot_1 = crt_size;
	if (loc == BOTTOM_B && crt_size < 8)
		*pivot_2 = crt_size / 2;
}
```

#### src/push_swap/chunk_sort.c

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:56:55 by ugerkens          #+#    #+#             */
/*   Updated: 2023/07/30 18:38:01 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ps *data)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = data->a.size;
	rec_chunk_sort(data, &chunk_all);
}

void	rec_chunk_sort(t_ps *data, t_chunk *to_sort)
{
	t_split_dest	dest;

	chunk_to_the_top(data, to_sort);
	easy_sort(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dest);
	rec_chunk_sort(data, &dest.max);
	rec_chunk_sort(data, &dest.mid);
	rec_chunk_sort(data, &dest.min);
}

void	sort_two(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
	{
		move_from_to(data, to_sort->loc, TOP_A);
		move_from_to(data, to_sort->loc, TOP_A);
	}
	if (value(&data->a, 1) > value(&data->a, 2))
		swap_a(data);
	to_sort->size -= 2;
}

void	sort_one(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
		move_from_to(data, to_sort->loc, TOP_A);
	to_sort->size -= 1;
}
```

#### Makefile

```/Makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:02:06 by ugerkens          #+#    #+#              #
#    Updated: 2025/01/22 17:15:50 by ugerkens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -Ofast
RM					=	rm -rf
CHECKER				=	checker
PUSH_SWAP			=	push_swap
NAME				=	$(PUSH_SWAP) $(CHECKER)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	lib/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	lib/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	src:src/stack:src/push_swap:src/checker_bonus:include
STACK_INC			=	stack.h
STACK_SRC			=	data_mngt.c stack_init.c stack_utils.c op_push.c \
						op_reverse_rotate.c op_rotate.c op_swap.c op_utils.c
PUSH_SWAP_INC		=	$(STACK_INC) push_swap.h
PUSH_SWAP_SRC		=	$(STACK_SRC) main.c sort.c move.c chunk_sort.c  \
						chunk_split.c chunk_utils.c opti_easy_sort.c \
						opti_sort_asap.c opti_sort_three.c opti_to_the_top.c \
						opti_post_sort.c opti_post_sort_utils.c
CHECKER_INC			=	$(STACK_INC) checker_bonus.h
CHECKER_SRC			=	$(STACK_SRC) checker_bonus.c checker_utils_bonus.c

# Rules
all:				$(PUSH_SWAP)

bonus:				$(CHECKER)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)
CHECKER_OBJ			= 	$(CHECKER_SRC:%.c=obj/checker/%.o)

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c $(PUSH_SWAP_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ):		obj/checker/%.o: %.c $(CHECKER_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(PUSH_SWAP):		$(LIB) $(PUSH_SWAP_OBJ)
					$(CC) $(CFLAGS) $(LIB) $(PUSH_SWAP_OBJ) -o $@

$(CHECKER):			$(LIB) $(CHECKER_OBJ)
					$(CC) $(CFLAGS) $(LIB) $(CHECKER_OBJ) -o $@

lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean

lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean

clean:				lib_clean
					$(RM) obj

fclean:				clean lib_fclean
					$(RM) $(NAME)

re:					fclean all

.SILENT:

.PHONY:				all bonus lib_clean lib_fclean clean fclean re
```

### Prompt

Explain a_partly_sort, what data structures it uses and how it works
