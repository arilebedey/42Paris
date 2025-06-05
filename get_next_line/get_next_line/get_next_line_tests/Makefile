NAME = gnl_test
STDIN_NAME = gnl_stdin
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Main test sources
SRCS = ../get_next_line.c \
       ../get_next_line_utils.c \
       test_get_next_line.c

# STDIN test sources
STDIN_SRCS = ../get_next_line.c \
             ../get_next_line_utils.c \
             test_stdin.c

OBJS = $(SRCS:.c=.o)
STDIN_OBJS = $(STDIN_SRCS:.c=.o)

BUFFER_SIZE ?= 42

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJS) -o $(NAME)

$(STDIN_NAME): $(STDIN_OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(STDIN_OBJS) -o $(STDIN_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(STDIN_OBJS)
	-rm -f test_*.txt 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	rm -f $(STDIN_NAME)

re: fclean all

stdin: $(STDIN_NAME)

test: all
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_stdin: stdin
	./$(STDIN_NAME)

# Test with different buffer sizes
test_small: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_medium: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

test_large: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(SRCS) -o $(NAME)
	./$(NAME)
	-rm -f test_*.txt 2>/dev/null || true

# Test STDIN with different buffer sizes
test_stdin_small: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

test_stdin_medium: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

test_stdin_large: clean
	$(CC) $(CFLAGS) -D BUFFER_SIZE=9999 $(STDIN_SRCS) -o $(STDIN_NAME)
	./$(STDIN_NAME)

.PHONY: all clean fclean re test stdin test_stdin test_small test_medium test_large test_stdin_small test_stdin_medium test_stdin_large
