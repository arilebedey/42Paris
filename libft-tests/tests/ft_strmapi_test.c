#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test function that converts index to uppercase if even, lowercase if odd
char	test_uppercase_even(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c >= 'a' && c <= 'z') ? c - 32 : c;
	else
		return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

// Test function that adds the index to the ASCII value of the character
char	test_add_index(unsigned int i, char c)
{
	return (c + i);
}

// Test function that returns the character uppercase
char	test_uppercase(unsigned int i, char c)
{
	(void)i;
	return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

// Test function that always returns 'X'
char	test_constant(unsigned int i, char c)
{
	(void)i;
	(void)c;
	return ('X');
}

// Utility function to check results
int	check_results(char *input, char *expected, char *result)
{
	(void) input;
	if (strcmp(expected, result) == 0)
		return (1);
	return (0);
}

int	main(void)
{
	char	*result;
	int		pass;
	
	printf("ft_strmapi\n");
	
	// Test 1 - Uppercase even indices
	char *input1 = "hello";
	char *expected1 = "HeLlO";
	result = ft_strmapi(input1, &test_uppercase_even);
	pass = check_results(input1, expected1, result);
	printf("%s: Test 1 - Uppercase even indices - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input1, result);
	free(result);
	
	// Test 2 - Add index to ASCII
	char *input2 = "abcde";
	char *expected2 = "acegi";
	result = ft_strmapi(input2, &test_add_index);
	pass = check_results(input2, expected2, result);
	printf("%s: Test 2 - Add index to ASCII - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input2, result);
	free(result);
	
	// Test 3 - All uppercase
	char *input3 = "mixed CASE";
	char *expected3 = "MIXED CASE";
	result = ft_strmapi(input3, &test_uppercase);
	pass = check_results(input3, expected3, result);
	printf("%s: Test 3 - All uppercase - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input3, result);
	free(result);
	
	// Test 4 - Empty string
	char *input4 = "";
	char *expected4 = "";
	result = ft_strmapi(input4, &test_uppercase);
	pass = check_results(input4, expected4, result);
	printf("%s: Test 4 - Empty string - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input4, result);
	free(result);
	
	// Test 5 - Constant function
	char *input5 = "hello world";
	char *expected5 = "XXXXXXXXXXX";
	result = ft_strmapi(input5, &test_constant);
	pass = check_results(input5, expected5, result);
	printf("%s: Test 5 - Constant function - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input5, result);
	free(result);
	
	// Test 6 - Special characters
	char *input6 = "!@#$%^";
	char *expected6 = "!@#$%^";
	result = ft_strmapi(input6, &test_uppercase);
	pass = check_results(input6, expected6, result);
	printf("%s: Test 6 - Special characters - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input6, result);
	free(result);
	
	// Test 7 - Numbers
	char *input7 = "123456";
	char *expected7 = "123456";
	result = ft_strmapi(input7, &test_uppercase);
	pass = check_results(input7, expected7, result);
	printf("%s: Test 7 - Numbers - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input7, result);
	free(result);

	// Test 8 - Long string
	char *input8 = "abcdefghijklmnopqrstuvwxyz";
	// Create the expected string manually by adding index to each character
	char expected8[27];
	for (int i = 0; i < 26; i++)
		expected8[i] = input8[i] + i;
	expected8[26] = '\0';
	result = ft_strmapi(input8, &test_add_index);
	pass = check_results(input8, expected8, result);
	printf("%s: Test 8 - Long string with index addition - Input: \"%s\" - Result: \"%s\"\n", 
		pass ? "SUCCESS" : "FAILURE", input8, result);
	free(result);
	
	return (0);
}
