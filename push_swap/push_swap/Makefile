CC						= cc
CFLAGS				= -Wall -Wextra -Werror -Iinclude -g
RM						= rm -rf
NAME					= push_swap
VPATH					= srcs

SRCS					= main.c atoi.c exit.c init.c segment_sort.c ints.c \
								len.c list_utils.c move_extremities.c op_push.c \
								op_revrotate.c op_rotate.c op_swap.c op_utils.c \
								segment_optimize.c segment_utils.c sort.c sort_second.c \
								sort_small_segment.c sort_three_segment.c split_segment.c \
								stack_utils.c write.c memset.c

OBJS					= $(SRCS:%.c=obj/%.o)

# Rules
all:						${NAME}

obj:
								mkdir -p obj

$(OBJS):				obj/%.o: %.c $(INCS) | obj
								$(CC) $(CFLAGS) -c $< -o $@

${NAME}:				${OBJS}
								${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:	
								${RM} obj

fclean:					clean
								${RM} ${NAME}

re: 						fclean all

.PHONY:					all clean fclean re
