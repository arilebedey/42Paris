#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run_test(int test_num, const char *description, const char *input, const char *set, const char *expected)
{
	char *result = ft_strtrim(input, set);
	int success = (result && strcmp(result, expected) == 0);
	
	printf("%s: Test %d - %s - Input: \"%s\" - Set: \"%s\" - Result: \"%s\"\n", 
		success ? "SUCCESS" : "FAILURE", 
		test_num,
		description,
		input,
		set,
		result ? result : "NULL");
	
	free(result);
}

int main(void)
{
	printf("ft_strtrim\n");
	
	// Test 1: Basic trim - spaces on both sides
	run_test(1, "Basic trim with spaces", "  hello  ", " ", "hello");
	
	// Test 2: Trim multiple set characters
	run_test(2, "Multiple set characters", "..hello...", ".", "hello");
	
	// Test 3: Nothing to trim
	run_test(3, "Nothing to trim", "hello", " ", "hello");
	
	// Test 4: Trim only at beginning
	run_test(4, "Trim only at beginning", "  hello", " ", "hello");
	
	// Test 5: Trim only at end
	run_test(5, "Trim only at end", "hello  ", " ", "hello");
	
	// Test 6: Empty string
	run_test(6, "Empty string", "", "abc", "");
	
	// Test 7: String with only set characters
	run_test(7, "String with only set characters", "   ", " ", "");
	
	// Test 8: Complex set
	run_test(8, "Complex set", "abc123abc", "abc", "123");
	
	// Test 9: Set not in string
	run_test(9, "Set not in string", "hello", "xyz", "hello");
	
	// Test 10: Nested trim characters
	run_test(10, "Nested trim characters", " a b c ", " ", "a b c");
	
	// Test 11: Set with multiple characters
	run_test(11, "Set with multiple characters", "abcdefabc", "abcdef", "");
	
	return (0);
}
