CC						= cc
CFLAGS				= -Wall -Wextra -Werror -Iinclude -g
RM						= rm -rf
NAME					= push_swap

SRCS					= main.c parse.c exit.c init.c segment_sort.c ints.c \
								len.c atoi.c  list_utils.c move_extremities.c \
								op_revrotate.c op_rotate.c op_swap.c op_utils.c \
								segment_utils.c sort.c place_second.c op_push.c \
								place_elements.c place_three_elements.c \
								stack_utils.c write.c memset.c split_segment.c

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

rc:
								$(MAKE) re && $(MAKE) clean

.PHONY:					all clean fclean re rc
