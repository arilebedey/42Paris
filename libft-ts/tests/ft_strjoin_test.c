#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	check_strjoin(char const *s1, char const *s2, char const *expected, int test_num, char *test_description)
{
	char	*result;
	int		success;

	result = ft_strjoin(s1, s2);
	success = (result && strcmp(result, expected) == 0);
	
	if (success)
		printf("SUCCESS: Test %d - %s - Input: \"%s\" + \"%s\" - Result: \"%s\"\n", 
			test_num, test_description, s1, s2, result);
	else
		printf("FAILURE: Test %d - %s - Input: \"%s\" + \"%s\" - Expected: \"%s\" - Got: \"%s\"\n", 
			test_num, test_description, s1, s2, expected, result ? result : "NULL");
	
	free(result);
	return (success);
}

int	main(void)
{
	int	success_count = 0;
	int	test_count = 0;

	printf("ft_strjoin\n");

	// Test 1: Basic joining of two simple strings
	test_count++;
	success_count += check_strjoin("Hello, ", "world!", "Hello, world!", test_count, "Basic joining");

	// Test 2: Joining with empty first string
	test_count++;
	success_count += check_strjoin("", "test", "test", test_count, "Empty first string");

	// Test 3: Joining with empty second string
	test_count++;
	success_count += check_strjoin("test", "", "test", test_count, "Empty second string");

	// Test 4: Joining two empty strings
	test_count++;
	success_count += check_strjoin("", "", "", test_count, "Both strings empty");

	// Test 5: Joining with special characters
	test_count++;
	success_count += check_strjoin("Special ", "!@#$%^&*()", "Special !@#$%^&*()", test_count, "Special characters");

	// Test 7: Joining strings with spaces
	test_count++;
	success_count += check_strjoin("   ", "   ", "      ", test_count, "Strings with spaces");
	return (0);
}
