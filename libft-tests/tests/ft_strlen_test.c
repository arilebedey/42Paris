#include <stdio.h>
#include "../libft/libft.h"

void run_test(const char *test_name, const char *input, int expected_result)
{
    int result = ft_strlen(input);
    
    if (result == expected_result)
        printf("SUCCESS: %s - Input: \"%s\" - Result: %d\n", test_name, input, result);
    else
        printf("FAILURE: %s - Input: \"%s\" - Expected: %d, Got: %d\n", test_name, input, expected_result, result);
}

int main(void)
{
    printf("ft_strlen\n");
    
    // Test cases
    run_test("Test 1 - Empty string", "", 0);
    run_test("Test 2 - Single character", "a", 1);
    run_test("Test 3 - Basic string", "Hello", 5);
    
    return 0;
}
