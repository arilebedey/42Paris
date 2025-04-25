NAME = bsq
NAME-g = a.out
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
d: $(NAME-g)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME-g): $(SRC)
	$(CC) $(CFLAGS) $^ -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME-g)

re: fclean all

.PHONY: all clean fclean re
