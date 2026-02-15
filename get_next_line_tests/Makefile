NAME = gnl_test
BONUS_NAME = gnl_test_bonus
STDIN_NAME = gnl_stdin
STDIN_BONUS_NAME = gnl_stdin_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Main test sources
SRCS = ../get_next_line.c \
       ../get_next_line_utils.c \
       test_get_next_line.c

# Bonus test sources
BONUS_SRCS = ../get_next_line_bonus.c \
             ../get_next_line_utils_bonus.c \
             test_get_next_line_bonus.c

# STDIN test sources
STDIN_SRCS = ../get_next_line.c \
             ../get_next_line_utils.c \
             test_stdin.c

# STDIN bonus test sources
STDIN_BONUS_SRCS = ../get_next_line_bonus.c \
                   ../get_next_line_utils_bonus.c \
                   test_stdin_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
STDIN_OBJS = $(STDIN_SRCS:.c=.o)
STDIN_BONUS_OBJS = $(STDIN_BONUS_SRCS:.c=.o)

BUFFER_SIZE ?= 42

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(BONUS_OBJS) -o $(BONUS_NAME)

$(STDIN_NAME): $(STDIN_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(STDIN_OBJS) -o $(STDIN_NAME)

$(STDIN_BONUS_NAME): $(STDIN_BONUS_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(STDIN_BONUS_OBJS) -o $(STDIN_BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(STDIN_OBJS)
	rm -f $(STDIN_BONUS_OBJS)
	-rm -f test_*.txt 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(STDIN_NAME)
	rm -f $(STDIN_BONUS_NAME)

re: fclean all

stdin: $(STDIN_NAME)

stdin_bonus: $(STDIN_BONUS_NAME)

test: all
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_bonus: bonus
	./$(BONUS_NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_stdin: stdin
	./$(STDIN_NAME)

test_stdin_bonus: stdin_bonus
	./$(STDIN_BONUS_NAME)

# Test with different buffer sizes
test_small: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_medium: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_large: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

# Bonus tests with different buffer sizes
test_bonus_small: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(BONUS_SRCS) -o $(BONUS_NAME)
	./$(BONUS_NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_bonus_medium: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(BONUS_SRCS) -o $(BONUS_NAME)
	./$(BONUS_NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_bonus_large: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(BONUS_SRCS) -o $(BONUS_NAME)
	./$(BONUS_NAME)
	-rm -f test_*.txt 2>/dev/null || true

# Test STDIN with different buffer sizes
test_stdin_small: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

test_stdin_medium: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

test_stdin_large: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

test_stdin_bonus_small: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(STDIN_BONUS_SRCS) -o $(STDIN_BONUS_NAME)
	./$(STDIN_BONUS_NAME)

test_stdin_bonus_medium: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(STDIN_BONUS_SRCS) -o $(STDIN_BONUS_NAME)
	./$(STDIN_BONUS_NAME)

test_stdin_bonus_large: fclean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(STDIN_BONUS_SRCS) -o $(STDIN_BONUS_NAME)
	./$(STDIN_BONUS_NAME)

.PHONY: all bonus clean fclean re test test_bonus stdin stdin_bonus test_stdin test_stdin_bonus \
        test_small test_medium test_large test_bonus_small test_bonus_medium test_bonus_large \
        test_stdin_small test_stdin_medium test_stdin_large \
        test_stdin_bonus_small test_stdin_bonus_medium test_stdin_bonus_large
