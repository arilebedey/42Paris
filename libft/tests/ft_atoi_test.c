#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

// Utility function to test ft_atoi against standard atoi
int test_atoi(const char *str, const char *test_name, int test_num)
{
    int result_ft = ft_atoi((char *)str);
    int result_std = atoi(str);
    
    if (result_ft == result_std)
    {
        printf("SUCCESS: Test %d - %s - Input: \"%s\" - Result: %d\n", 
               test_num, test_name, str, result_ft);
        return 1; // Success
    }
    else
    {
        printf("FAIL: Test %d - %s - Input: \"%s\" - ft_atoi: %d, stdlib atoi: %d\n", 
               test_num, test_name, str, result_ft, result_std);
        return 0; // Failure
    }
}

int main(void)
{
    printf("ft_atoi\n");
    
    // Test 1: Basic positive number
    test_atoi("42", "Basic positive number", 1);
    
    // Test 2: Negative number with whitespace
    test_atoi("  -42", "Negative number with whitespace", 2);
    
    // Test 3: Complex sign handling
    test_atoi("--++-123", "Multiple signs", 3);
    
    // Test 4: Number followed by non-digits
    test_atoi("123abc", "Number followed by non-digits", 4);
    
    // Test 5: Spaces followed by multiple dashes
    test_atoi("     ----20", "Spaces followed by multiple dashes", 5);
    
    // Test 6: Multiple dashes before number
    test_atoi("-----10", "Multiple dashes before number", 6);
    
    // Test 7: Multiple plus signs before number
    test_atoi("+++++6 ", "Multiple plus signs before number and space after", 7);
    
    // Test 8: Mixed signs
    test_atoi("---+++3", "Mixed signs", 8);

    // Test 9
	test_atoi("+42", "Single positive sign", 9);

    return 0;
}
