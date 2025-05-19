NAME = test_printf

CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =
INCLUDES = -I ../

SRCS = ./tests.c
OBJS = $(SRCS:.c=.o)

all: run-test fclean

run-test: $(NAME)
	./$(NAME)

$(NAME): test

test: ../ft_printf.a
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) ../libftprintf.a -o $(NAME)

../ft_printf.a:
	$(MAKE) -C ..

clean:
	rm -f $(OBJS)
	$(MAKE) -C .. clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C .. fclean

re: fclean all

.PHONY: all clean fclean re test
