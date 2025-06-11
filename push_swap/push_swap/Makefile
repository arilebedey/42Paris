CC						= cc
CFLAGS				= -Wall -Wextra -Werror -g
RM						= rm -rf
NAME					= push_swap

SRCS					= main.c atoi.c exit.c init.c segment_sort.c ints.c \
								len.c list_utils.c move_extremities.c op_push.c \
								op_revrotate.c op_rotate.c op_swap.c op_utils.c \
								segment_utils.c sort.c place_second_elem.c \
								place_elements.c place_three_elements.c split_segment.c \
								stack_utils.c write.c memset.c segment_optimize.c

OBJS					= $(SRCS:%.c=obj/%.o)

# Rules
all:						${NAME}

obj:
								mkdir -p obj

$(OBJS):				obj/%.o: %.c $(INCS) | obj
								$(CC) $(CFLAGS) -c $< -o $@

$(NAME):				$(OBJS)
								${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:	
								${RM} obj

fclean:					clean
								${RM} ${NAME}

re: 						fclean all

.PHONY:					all clean fclean re
