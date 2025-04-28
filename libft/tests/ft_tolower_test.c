#include "../libft/libft.h"
#include <stdio.h>

void run_test(char *test_name, int input, int expected)
{
    int result = ft_tolower(input);
    if (result == expected)
        printf("SUCCESS: %s - Input: '%c' - Result: '%c'\n", test_name, input, result);
    else
        printf("FAILURE: %s - Input: '%c' - Expected: '%c', Got: '%c'\n", test_name, input, expected, result);
}

int main(void)
{
    printf("ft_tolower\n");
    
    // Test 1: 'A' should convert to 'a'
    run_test("Test 1 - Convert uppercase 'A'", 'A', 'a');
    
    // Test 2: 'Z' should convert to 'z'
    run_test("Test 2 - Convert uppercase 'Z'", 'Z', 'z');
    
    // Test 3: '@' (just before 'A') should remain unchanged
    run_test("Test 3 - Character before 'A'", '@', '@');
    
    // Test 4: '[' (just after 'Z') should remain unchanged
    run_test("Test 4 - Character after 'Z'", '[', '[');
    
    return (0);
}
