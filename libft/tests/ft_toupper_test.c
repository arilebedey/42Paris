#include "../libft/libft.h"
#include <stdio.h>

void run_test(char *test_name, int input, int expected)
{
    int result = ft_toupper(input);
    if (result == expected)
        printf("SUCCESS: %s - Input: '%c' - Result: '%c'\n", test_name, input, result);
    else
        printf("FAILURE: %s - Input: '%c' - Expected: '%c', Got: '%c'\n", test_name, input, expected, result);
}

int main(void)
{
    printf("ft_toupper\n");
    
    // Test 1: 'a' should convert to 'A'
    run_test("Test 1 - Convert lowercase 'a'", 'a', 'A');
    
    // Test 2: 'z' should convert to 'Z'
    run_test("Test 2 - Convert lowercase 'z'", 'z', 'Z');
    
    // Test 3: '`' (just before 'a') should remain unchanged
    run_test("Test 3 - Character before 'a'", '`', '`');
    
    // Test 4: '{' (just after 'z') should remain unchanged
    run_test("Test 4 - Character after 'z'", '{', '{');
    
    return (0);
}
