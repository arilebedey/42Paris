/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:20:35 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/02 15:54:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


/**
 * Color codes for test output formatting
 */
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

/**
 * Test STDIN
 * Reads from standard input line by line using get_next_line
 * Press Ctrl+D (EOF) to finish input
 */
int	main(void)
{
	char	*line;
	int		line_count;

	line_count = 0;
	printf(YELLOW "=== GET_NEXT_LINE STDIN TESTER ===" RESET "\n\n");
	printf(BLUE "Buffer size: %d\n" RESET, BUFFER_SIZE);
	printf(BLUE "Enter text (press Ctrl+D when finished):\n" RESET);
	
	while ((line = get_next_line(0)) != NULL)
	{
		line_count++;
		printf(GREEN "Line %d: " RESET "%s", line_count, line);
		
		// If the line doesn't end with a newline, add one for formatting
		if (line[0] != '\0' && line[strlen(line) - 1] != '\n')
			printf("\n");
		
		free(line);
	}
	
	printf("\n" YELLOW "=== TEST COMPLETED ===" RESET "\n");
	printf(BLUE "Read %d lines from standard input\n" RESET, line_count);
	
	return (0);
}
