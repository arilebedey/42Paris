#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/**
 * Color codes for test output formatting
 */
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

/**
 * Create test files with various patterns
 */
void	create_test_files(void)
{
	int		fd;
	
	// Normal file with multiple lines
	fd = open("test_normal.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "This is line 1\n", 15);
	write(fd, "This is line 2\n", 15);
	write(fd, "This is line 3\n", 15);
	write(fd, "This is line 4\n", 15);
	write(fd, "This is line 5 with no newline", 30);
	close(fd);
	
	// Empty file
	fd = open("test_empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(fd);
	
	// File with only newlines
	fd = open("test_only_newlines.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "\n\n\n\n\n", 5);
	close(fd);
	
	// File with one long line
	fd = open("test_one_long_line.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "This is one very long line without any newline characters. ", 59);
	write(fd, "It should test the functionality of your get_next_line with ", 59);
	write(fd, "a buffer size smaller than the line length.", 42);
	close(fd);
	
	// File with mixed line lengths
	fd = open("test_mixed.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "Short\n", 6);
	write(fd, "A bit longer line\n", 18);
	write(fd, "An even longer line with more characters\n", 41);
	write(fd, "And another loooooooooooooooooooooooooooooooooong line\n", 55);
	write(fd, "\n", 1);
	write(fd, "End", 3);
	close(fd);
}

/**
 * Run tests for a single file
 */
void	test_file(const char *filename, int expected_lines)
{
	int		fd;
	char	*line;
	int		line_count = 0;
	
	printf(BLUE "Testing file: %s" RESET "\n", filename);
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(RED "  Error: Could not open %s\n" RESET, filename);
		return ;
	}
	
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		printf("  Line %d: %s", line_count, line);
		// If the line doesn't end with a newline, add one for formatting
		if (line[0] != '\0' && line[strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
	
	close(fd);
	
	if (expected_lines == -1 || line_count == expected_lines)
		printf(GREEN "  Test passed! Read %d lines\n" RESET, line_count);
	else
		printf(RED "  Test failed! Expected %d lines, got %d\n" RESET, 
				expected_lines, line_count);
	printf("\n");
}

/**
 * Test reading from multiple file descriptors
 */
void	test_multiple_fds(void)
{
	int		fd1, fd2, fd3;
	char	*line1, *line2, *line3;
	
	printf(BLUE "Testing multiple file descriptors" RESET "\n");
	
	fd1 = open("test_normal.txt", O_RDONLY);
	fd2 = open("test_only_newlines.txt", O_RDONLY);
	fd3 = open("test_mixed.txt", O_RDONLY);
	
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf(RED "  Error: Could not open one or more files\n" RESET);
		return ;
	}
	
	// Read first line from each file
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	
	printf("  FD1, Line 1: %s", line1);
	printf("  FD2, Line 1: %s", line2);
	printf("  FD3, Line 1: %s", line3);
	
	free(line1);
	free(line2);
	free(line3);
	
	// Read second line from each file
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	
	printf("  FD1, Line 2: %s", line1);
	printf("  FD2, Line 2: %s", line2);
	printf("  FD3, Line 2: %s", line3);
	
	free(line1);
	free(line2);
	free(line3);
	
	close(fd1);
	close(fd2);
	close(fd3);
	
	printf(GREEN "  Test completed!\n" RESET);
	printf("\n");
}

/**
 * Test invalid file descriptors
 */
void	test_invalid_fd(void)
{
	char	*line;
	
	printf(BLUE "Testing invalid file descriptors" RESET "\n");
	
	// Test with negative FD
	line = get_next_line(-1);
	if (line == NULL)
		printf(GREEN "  Test with FD -1: Passed (returned NULL)\n" RESET);
	else
	{
		printf(RED "  Test with FD -1: Failed (did not return NULL)\n" RESET);
		free(line);
	}
	
	// Test with unopened FD
	line = get_next_line(42);
	if (line == NULL)
		printf(GREEN "  Test with FD 42: Passed (returned NULL)\n" RESET);
	else
	{
		printf(RED "  Test with FD 42: Failed (did not return NULL)\n" RESET);
		free(line);
	}
	
	printf("\n");
}

/**
 * Test STDIN
 */
void	test_stdin(void)
{
	printf(BLUE "Testing STDIN (enter a few lines, press Ctrl+D to finish)" RESET "\n");
	
	char	*line;
	int		line_count = 0;
	
	while ((line = get_next_line(0)) != NULL)
	{
		line_count++;
		printf("  Read line %d: %s", line_count, line);
		free(line);
	}
	
	printf(GREEN "  Test completed! Read %d lines from STDIN\n" RESET, line_count);
	printf("\n");
}

/**
 * Main test function
 */
int		main(void)
{
	printf(YELLOW "=== GET_NEXT_LINE TESTER ===" RESET "\n");
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	
	// Create test files
	create_test_files();
	
	// Test each file
	test_file("test_normal.txt", 5);
	test_file("test_empty.txt", 0);
	test_file("test_only_newlines.txt", 5);
	test_file("test_one_long_line.txt", 1);
	test_file("test_mixed.txt", 6);
	
	// Test multiple file descriptors
	test_multiple_fds();
	
	// Test invalid file descriptors
	test_invalid_fd();
	
	// Uncomment to test STDIN (requires user input)
	// test_stdin();
	
	printf(YELLOW "=== ALL TESTS COMPLETED ===" RESET "\n");
	return (0);
}
