NAME = test_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../

SRC_DIR = ./
SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): test
	./$(NAME)

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
