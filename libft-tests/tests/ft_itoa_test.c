#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_ft_itoa(int input, char *expected)
{
    char *result = ft_itoa(input);
    if (result && strcmp(result, expected) == 0)
        printf("SUCCESS: Test - Input: %d - Result: \"%s\"\n", input, result);
    else
        printf("FAILURE: Test - Input: %d - Expected: \"%s\" - Got: \"%s\"\n", input, expected, result);
    
    if (result)
        free(result);
}

int main(void)
{
	printf("ft_itoa\n");
    // Test 1: Basic positive number
    test_ft_itoa(42, "42");
    
    // Test 2: Basic negative number
    test_ft_itoa(-42, "-42");
    
    // Test 3: Zero
    test_ft_itoa(0, "0");
    
    // Test 4: Single digit
    test_ft_itoa(7, "7");
    
    // Test 5: Large positive number
    test_ft_itoa(2147483647, "2147483647");
    
    // Test 6: Minimum integer
    test_ft_itoa(-2147483648, "-2147483648");
    
    // Test 7: Multiple digits
    test_ft_itoa(123456, "123456");
    
    // Test 8: Negative multiple digits
    test_ft_itoa(-98765, "-98765");
    
    // Test 9: Positive number with leading zeros in normal representation
    test_ft_itoa(42000, "42000");
    
    return (0);
}
