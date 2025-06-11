CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = swapper

SRCS = main.c swapper.c stack_utils.c op_push.c op_swap.c op_rotate.c op_revrotate.c \
       ints.c atoi.c len.c memset.c exit.c init.c

OBJS = $(SRCS:%.c=obj/%.o)

all: $(NAME)

obj:
	mkdir -p obj

$(OBJS): obj/%.o: %.c push_swap.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
