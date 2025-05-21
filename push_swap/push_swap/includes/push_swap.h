/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:57:42 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/21 11:57:42 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void				*operation;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef struct s_stack
{
	int					*values;
	int					newest_idx;
	int					oldest_idx;
	int					capacity;
}						t_stack;

typedef struct s_opnode
{
	void				*operation;
	struct s_opnode		*prev;
	struct s_opnode		*next;
}						t_opnode;

typedef struct s_context
{
	t_stack				stack_a;
	t_stack				stack_b;
	t_opnode			*op_hist;
}						t_context;

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
}						t_ops;

typedef enum s_stack_location
{
	LOCATION_TOP_A,
	LOCATION_TOP_B,
	LOCATION_BOTTOM_A,
	LOCATION_BOTTOM_B,
}						t_stack_location;

typedef struct s_stack_segmnt
{
	t_stack_location	location;
	int					elem_count;
}						t_stack_segmnt;

typedef struct s_segmnt_split
{
	t_stack_segmnt		min_values;
	t_stack_segmnt		mid_values;
	t_stack_segmnt		max_values;
}						t_segmnt_split;

// Basic helpers
size_t					ft_strlen(const char *s);
void					ft_putendl_fd(char *s, int fd);
int						ft_atoi(char *str);

// Parsing
void					handle_error(t_context *ctx);
void					clear_list(t_opnode **list);
bool					is_valid_int(char *str);
void					init_context(t_context *ctx, int argc, char **argv);

// Stack Ops
int						get_stack_size(t_stack *stack);
int						get_next_bottom_idx(t_stack *stack, int current_idx);
int						get_next_top_idx(t_stack *stack, int current_idx);

// Sorting

#endif
