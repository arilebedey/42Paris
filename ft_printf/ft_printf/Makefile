NAME := libftprintf.a
TEST := test_printf

SRCS := ft_printf.c numbers.c pointers.c chars.c
OBJS := $(SRCS:.c=.o)

MAIN := main.c
MAIN_OBJ := $(MAIN:.c=.o)

CC := cc
CFLAGS := -Wall -Werror -Wextra -I ./

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)

# Build test executable linking the static library with main
$(TEST): $(NAME) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(NAME) -o $(TEST)

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test
