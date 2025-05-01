LIBFT_DIR := ..
LIB := $(LIBFT_DIR)/libft.a
TESTS_DIR := tests

# Test source files
TEST_SRCS := $(wildcard $(TESTS_DIR)/*.c)
TEST_BINS := $(patsubst %.c,%.out,$(TEST_SRCS))

CC := gcc
CFLAGS := -Wall -Werror -Wextra -I $(LIBFT_DIR)
LDFLAGS := -L$(LIBFT_DIR) -lft -lbsd

# Default target - build library and run tests
all: $(LIB) run_tests

# Build the library by running the root Makefile
$(LIB):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Compile test files into executables
$(TESTS_DIR)/%.out: $(TESTS_DIR)/%.c $(LIB)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

# Build and run all tests
run_tests: $(TEST_BINS)
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
	@$(MAKE) fclean

clean:
	rm -f $(TEST_BINS)
	rm -f $(TESTS_DIR)/test*.txt

fclean: clean
	@echo "Cleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean run_tests
