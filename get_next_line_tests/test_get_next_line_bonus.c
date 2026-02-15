/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:41:29 by alebedev          #+#    #+#             */
/*   Updated: 2026/02/15 20:42:25 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

void	create_test_files(void)
{
	int		fd;
	
	fd = open("test_normal.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "This is line 1\n", 15);
	write(fd, "This is line 2\n", 15);
	write(fd, "This is line 3\n", 15);
	write(fd, "This is line 4\n", 15);
	write(fd, "This is line 5 with no newline", 30);
	close(fd);
	
	fd = open("test_empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(fd);
	
	fd = open("test_only_newlines.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "\n\n\n\n\n", 5);
	close(fd);
	
	fd = open("test_one_long_line.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "This is one very long line without any newline characters. ", 59);
	write(fd, "It should test the functionality of your get_next_line with ", 59);
	write(fd, "a buffer size smaller than the line length.", 42);
	close(fd);
	
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
	
	fd = open("test_file_a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "File A - Line 1\n", 16);
	write(fd, "File A - Line 2\n", 16);
	write(fd, "File A - Line 3\n", 16);
	close(fd);
	
	fd = open("test_file_b.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "File B - Line 1\n", 16);
	write(fd, "File B - Line 2\n", 16);
	write(fd, "File B - Line 3\n", 16);
	close(fd);
	
	fd = open("test_file_c.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, "File C - Line 1\n", 16);
	write(fd, "File C - Line 2\n", 16);
	write(fd, "File C - Line 3\n", 16);
	close(fd);
}

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

void	test_interleaved_multiple_fds(void)
{
	int		fd_a, fd_b, fd_c;
	char	*line_a, *line_b, *line_c;
	int		count_a = 0, count_b = 0, count_c = 0;
	
	printf(MAGENTA "=== Testing Interleaved Multiple File Descriptors ===" RESET "\n");
	
	fd_a = open("test_file_a.txt", O_RDONLY);
	fd_b = open("test_file_b.txt", O_RDONLY);
	fd_c = open("test_file_c.txt", O_RDONLY);
	
	if (fd_a == -1 || fd_b == -1 || fd_c == -1)
	{
		printf(RED "  Error: Could not open one or more files\n" RESET);
		return ;
	}
	
	printf(BLUE "Reading in pattern: A, B, C, A, B, C, A, B, C\n" RESET);
	
	while (1)
	{
		int	has_data = 0;
		
		if ((line_a = get_next_line(fd_a)) != NULL)
		{
			count_a++;
			printf("  FD_A[%d]: %s", count_a, line_a);
			free(line_a);
			has_data = 1;
		}
		
		if ((line_b = get_next_line(fd_b)) != NULL)
		{
			count_b++;
			printf("  FD_B[%d]: %s", count_b, line_b);
			free(line_b);
			has_data = 1;
		}
		
		if ((line_c = get_next_line(fd_c)) != NULL)
		{
			count_c++;
			printf("  FD_C[%d]: %s", count_c, line_c);
			free(line_c);
			has_data = 1;
		}
		
		if (!has_data)
			break ;
	}
	
	close(fd_a);
	close(fd_b);
	close(fd_c);
	
	if (count_a == 3 && count_b == 3 && count_c == 3)
		printf(GREEN "  Test passed! Read all lines from each FD\n" RESET);
	else
		printf(RED "  Test failed! Got A:%d B:%d C:%d (expected 3 each)\n" RESET,
				count_a, count_b, count_c);
	printf("\n");
}

void	test_mixed_fd_pattern(void)
{
	int		fd_a, fd_b, fd_c;
	char	*line;
	int		pattern[9] = {0, 1, 2, 1, 0, 2, 0, 1, 2};
	int		fd_array[3];
	int		fd_index;
	int		result[3] = {0, 0, 0};
	
	printf(MAGENTA "=== Testing Complex FD Pattern ===" RESET "\n");
	
	fd_a = open("test_file_a.txt", O_RDONLY);
	fd_b = open("test_file_b.txt", O_RDONLY);
	fd_c = open("test_file_c.txt", O_RDONLY);
	
	if (fd_a == -1 || fd_b == -1 || fd_c == -1)
	{
		printf(RED "  Error: Could not open one or more files\n" RESET);
		return ;
	}
	
	fd_array[0] = fd_a;
	fd_array[1] = fd_b;
	fd_array[2] = fd_c;
	
	printf(BLUE "Reading pattern: A, B, C, B, A, C, A, B, C\n" RESET);
	
	for (int i = 0; i < 9; i++)
	{
		fd_index = pattern[i];
		line = get_next_line(fd_array[fd_index]);
		
		if (line != NULL)
		{
			result[fd_index]++;
			printf("  Read[%d] from FD_%c: %s", i, 'A' + fd_index, line);
			free(line);
		}
	}
	
	close(fd_a);
	close(fd_b);
	close(fd_c);
	
	printf("\nResults: FD_A: %d, FD_B: %d, FD_C: %d\n", result[0], result[1], result[2]);
	
	if (result[0] > 0 && result[1] > 0 && result[2] > 0)
		printf(GREEN "  Test passed! Successfully managed multiple FDs\n" RESET);
	else
		printf(RED "  Test failed! One or more FDs had issues\n" RESET);
	printf("\n");
}

void	test_invalid_fd(void)
{
	char	*line;
	
	printf(BLUE "Testing invalid file descriptors" RESET "\n");
	
	line = get_next_line(-1);
	if (line == NULL)
		printf(GREEN "  Test with FD -1: Passed (returned NULL)\n" RESET);
	else
	{
		printf(RED "  Test with FD -1: Failed (did not return NULL)\n" RESET);
		free(line);
	}
	
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

int		main(void)
{
	printf(YELLOW "=== GET_NEXT_LINE BONUS TESTER ===" RESET "\n");
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	
	create_test_files();
	
	test_file("test_normal.txt", 5);
	test_file("test_empty.txt", 0);
	test_file("test_only_newlines.txt", 5);
	test_file("test_one_long_line.txt", 1);
	test_file("test_mixed.txt", 6);
	
	test_interleaved_multiple_fds();
	
	test_mixed_fd_pattern();
	
	test_invalid_fd();
	
	printf(YELLOW "=== ALL BONUS TESTS COMPLETED ===" RESET "\n");
	return (0);
}
