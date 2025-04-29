LIB := libft.a
LIBFT_DIR := libft
TESTS_DIR := tests

LIBC :=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c 
ADDITIONAL :=	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

SRCS := $(LIBC) $(ADDITIONAL)
OBJS := $(addprefix $(LIBFT_DIR)/, $(SRCS:.c=.o))

# Test source files
TEST_SRCS := $(wildcard $(TESTS_DIR)/*.c)
TEST_BINS := $(TEST_SRCS:.c=.out)

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I $(LIBFT_DIR)
LDFLAGS := -L$(LIBFT_DIR) -lft -lbsd

# Build the library
$(LIBFT_DIR)/$(LIB): $(OBJS)
	ar -rsc $@ $(OBJS)

# Compile library objects
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test files into executables
$(TESTS_DIR)/%.out: $(TESTS_DIR)/%.c $(LIBFT_DIR)/$(LIB)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

all: $(LIBFT_DIR)/$(LIB)

# Build and run all tests
tests: $(TEST_BINS)
	@echo "Running all tests..."
	@rm -f test_output.log
	@for test in $(TEST_BINS); do \
		echo "\n--- Running $${test} ---"; \
		./$${test} | tee -a test_output.log; \
	done
	@echo "\n---------------------------------"
	@echo "Test Summary:"
	@failures=$$(grep -c "FAILURE" test_output.log || true); \
	echo "Total failures: $${failures}"; \
	if [ "$${failures}" -gt 0 ]; then \
		echo "Failed tests:"; \
		grep -n "FAILURE" test_output.log || true; \
	else \
		echo "All tests passed!"; \
	fi
	@rm -f test_output.log

clean:
	rm -f $(OBJS)
	rm -f $(TEST_BINS)
	rm test*.txt

fclean: clean
	rm -f $(LIBFT_DIR)/$(LIB)

re: fclean all

.PHONY: all clean fclean re tests
