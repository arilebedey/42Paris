/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:57:42 by alebedev        #+#    #+#             */
/*   Updated: 2025/06/17 15:37:01 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*values;
	int		newest_idx;
	int		oldest_idx;
	int		capacity;
}			t_stack;

typedef struct s_context
{
	t_stack	stack_a;
	t_stack	stack_b;
}			t_context;

typedef enum e_ops
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}			t_ops;

// BASIC FUNCTIONS
size_t		ft_strlen(const char *s);
int			ft_atoi(char *str);
void		*ft_memset(void *b, int c, size_t len);

// PARSING FUNCTIONS
bool		is_valid_int(char *str);
void		init_context(t_context *ctx, int argc, char **argv);

// STACK UTILITY FUNCTIONS
int			get_stack_size(t_stack *stack);
bool		is_stack_full(t_stack *stack);
int			get_next_bottom_idx(t_stack *stack, int current_idx);
int			get_next_top_idx(t_stack *stack, int current_idx);
int			value_at(t_stack *stack, int pos);

// OPERATIONS ON STACKS
void		push(t_stack *src, t_stack *dst);
void		push_a(t_context *ctx);
void		push_b(t_context *ctx);
void		swap(t_stack *stack);
void		swap_a(t_context *ctx);
void		swap_b(t_context *ctx);
void		swap_ab(t_context *ctx);
void		rotate(t_stack *stack);
void		rotate_a(t_context *ctx);
void		rotate_b(t_context *ctx);
void		rotate_ab(t_context *ctx);
void		r_rotate(t_stack *stack);
void		r_rotate_a(t_context *ctx);
void		r_rotate_b(t_context *ctx);
void		r_rotate_ab(t_context *ctx);

// SWAPPER FUNCTIONS
void		apply_operations(t_context *ctx);
void		print_stack(t_stack *stack);

// EXITING
void		free_context(t_context *ctx);
void		handle_error(t_context *ctx);

#endif
