/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/29 12:36:41 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int	run_test(const void *s, int c, size_t n, const char *test_name, const char *input_desc)
{
	void	*expected;
	void	*actual;
	int		result;

	expected = memchr(s, c, n);
	actual = ft_memchr(s, c, n);
	result = (expected == actual);
	
	if (result)
		printf("SUCCESS: %s - Input: %s - Result: %p\n", test_name, input_desc, actual);
	else
		printf("FAILURE: %s - Input: %s - Expected: %p, Got: %p\n", test_name, input_desc, expected, actual);
	
	return (result);
}

int	main(void)
{
	int		success_count;
	int		total_tests;
	char	test_string[] = "Hello, World!";
	int		test_array[] = {1, 2, 3, 4, 5};
	char	test_empty[] = "";
	
	success_count = 0;
	total_tests = 9;
	
	printf("ft_memchr\n");
	
	/* Test 1: Find character in string */
	success_count += run_test(test_string, 'W', 13, "Test 1 - Find character in string", "'Hello, World!', 'W', 13");
	
	/* Test 2: Find character not in string */
	success_count += run_test(test_string, 'Z', 13, "Test 2 - Character not in string", "'Hello, World!', 'Z', 13");
	
	/* Test 3: Find character with limited length */
	success_count += run_test(test_string, 'o', 5, "Test 3 - Limited search length", "'Hello, World!', 'o', 5");
	
	/* Test 4: Find null character */
	success_count += run_test(test_string, '\0', 14, "Test 4 - Find null terminator", "'Hello, World!', '\\0', 14");
	
	/* Test 5: Search in empty string */
	success_count += run_test(test_empty, 'a', 0, "Test 5 - Empty string", "Empty string, 'a', 0");
	
	/* Test 6: Search in integer array */
	success_count += run_test(test_array, 3, 5 * sizeof(int), "Test 6 - Search in integer array", "Int array [1,2,3,4,5], 3, 5*sizeof(int)");
	
	/* Test 7: Search with zero length */
	success_count += run_test(test_string, 'H', 0, "Test 7 - Zero length search", "'Hello, World!', 'H', 0");
	
	/* Test 8: Find first occurrence in multiple occurrences */
	success_count += run_test(test_string, 'l', 13, "Test 8 - Find first occurrence", "'Hello, World!', 'l', 13");
	
	/* Test 9: Find byte value > 127 */
	success_count += run_test(test_string, 300, 13, "Test 9 - High ASCII value", "'Hello, World!', 300 (44 after casting), 13");
	(void) total_tests;
	
	return (0);
}
