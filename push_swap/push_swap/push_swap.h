/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:57:42 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/19 22:59:59 by alebedev         ###   ########.fr       */
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
	bool				args_allocated;
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
	t_stack_location	loc;
	int					count;
}						t_stack_segmnt;

typedef struct s_segmnt_split
{
	t_stack_segmnt		min;
	t_stack_segmnt		mid;
	t_stack_segmnt		max;
}						t_segmnt_split;

// BASIC FUNCTIONS
size_t					ft_strlen(const char *s);
void					ft_putendl_fd(char *s, int fd);
int						ft_atoi(char *str);
void					*ft_memset(void *b, int c, size_t len);

// LIST FUNCTIONS
void					clear_list(t_opnode **list);
t_opnode				*new_opnode(void *operation);
void					add_opnode_back(t_opnode **lst, t_opnode *to_add);

// PARSING FUNCTIONS
char					**parse_args(int *argc, char **argv);
bool					is_valid_int(char *str);
void					init_context(t_context *ctx, int argc, char **argv);

// STACK UTILITY FUNCTIONS
int						get_stack_size(t_stack *stack);
bool					is_stack_full(t_stack *stack);
int						get_next_bottom_idx(t_stack *stack, int current_idx);
int						get_next_top_idx(t_stack *stack, int current_idx);
int						value_at(t_stack *stack, int pos);

// OPERATION UTILITY FUNCTIONS
void					record_op(t_context *ctx, t_ops op);

// OPERATIONS ON STACKS
void					push_a(t_context *ctx);
void					push_b(t_context *ctx);
void					swap_a(t_context *ctx);
void					swap_b(t_context *ctx);
void					swap_ab(t_context *ctx);
void					rotate_a(t_context *ctx);
void					rotate_b(t_context *ctx);
void					rotate_ab(t_context *ctx);
void					r_rotate_a(t_context *ctx);
void					r_rotate_b(t_context *ctx);
void					r_rotate_ab(t_context *ctx);

// SPLITTING UTILITY FUNCTIONS
void					approach_seg_from_top(t_context *ctx,
							t_stack_segmnt *seg);
int						segment_value(t_context *ctx, t_stack_segmnt *seg,
							int n);
void					split_segment(t_context *ctx, t_stack_segmnt *seg,
							t_segmnt_split *split);

// SEGMENT UTILITY FUNCTIONS
int						segment_max_value(t_context *ctx, t_stack_segmnt *seg);
t_stack					*stack_from_location(t_context *ctx,
							t_stack_location loc);
bool					is_stack_a_part_sorted(t_context *ctx, int start_pos);
void					reduce_max_segment(t_context *ctx, t_stack_segmnt *seg);

// SORTING FUNCTIONS
void					recursive_segment_sort(t_context *ctx);
void					place_elements(t_context *ctx, t_stack_segmnt *seg);
int						move_to_loc(t_context *ctx, t_stack_location from,
							t_stack_location to);
void					place_second(t_context *ctx, t_stack_segmnt *seg);
void					place_one_element(t_context *ctx, t_stack_segmnt *seg);
void					place_two_elements(t_context *ctx, t_stack_segmnt *seg);
void					place_three_elements(t_context *ctx,
							t_stack_segmnt *seg);
void					sort(t_context *ctx);

// PRINTING
void					print_operations(t_opnode *op_list);

// EXITING
void					free_args(char **args);
void					early_error(void);
void					handle_error(t_context *ctx);
void					handle_exit(t_context *ctx);
void					free_context(t_context *ctx);

#endif
