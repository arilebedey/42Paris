NAME = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../

SRCS = ./*.c
OBJS = $(SRCS:.c=.o)

all: run-test fclean

run-test: $(NAME)
	./$(NAME)

$(NAME): test

test: ../libftprintf.a
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) ../libftprintf.a -o $(NAME)

../libftprintf.a:
	$(MAKE) -C ..

clean:
	rm -f $(OBJS)
	$(MAKE) -C .. clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C .. fclean

re: fclean all

.PHONY: all clean fclean re test
