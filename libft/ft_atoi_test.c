#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Utility function to test ft_atoi against standard atoi
int test_atoi(const char *str, const char *test_name)
{
    int result_ft = ft_atoi((char *)str);
    int result_std = atoi(str);
    
    if (result_ft == result_std)
    {
        printf("SUCCESS: %s - Input: \"%s\" - Result: %d\n", 
               test_name, str, result_ft);
        return 1; // Success
    }
    else
    {
        printf("FAIL: %s - Input: \"%s\" - ft_atoi: %d, stdlib atoi: %d\n", 
               test_name, str, result_ft, result_std);
        return 0; // Failure
    }
}

int main(void)
{
    int success_count = 0;
    int total_tests = 5;
    
    printf("ft_atoi Test Suite (5 Crucial Tests)\n");
    printf("===================================\n\n");
    
    // Test 1: Basic positive number
    success_count += test_atoi("42", "Test 1 - Basic positive number");
    
    // Test 2: Basic negative number with spaces
    success_count += test_atoi("  -42", "Test 2 - Negative number with whitespace");
    
    // Test 3: Complex multiple signs (tests sign handling)
    success_count += test_atoi("--++-123", "Test 3 - Multiple signs");
    
    // Test 4: Non-digit after number (tests stopping at non-digits)
    success_count += test_atoi("123abc", "Test 4 - Number followed by non-digits");
    
    // Test 5: All whitespace characters (tests whitespace handling)
    success_count += test_atoi("\t\n\v\f\r 42", "Test 5 - All whitespace characters");
    
    // Print summary
    printf("\nTest Summary: %d/%d tests passed\n", success_count, total_tests);
    
    return (success_count == total_tests) ? 0 : 1;
}
