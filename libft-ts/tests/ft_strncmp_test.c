#include "../libft/libft.h"
#include <stdio.h>
#include <bsd/string.h>

typedef struct s_test {
    const char *s1;
    const char *s2;
    size_t n;
    int expected;
} t_test;

int run_test(int test_num, const char *description, const char *s1, const char *s2, size_t n)
{
    int result = ft_strncmp(s1, s2, n);
    int expected = strncmp(s1, s2, n);
    
    // Make sure we're comparing the same sign, not exact values
    int result_sign = (result > 0) ? 1 : (result < 0) ? -1 : 0;
    int expected_sign = (expected > 0) ? 1 : (expected < 0) ? -1 : 0;
    
    if (result_sign == expected_sign)
    {
        printf("SUCCESS: Test %d - %s - Input: \"%s\", \"%s\", %zu - Result: %d\n", 
               test_num, description, s1, s2, n, result);
        return 1;
    }
    else
    {
        printf("FAILURE: Test %d - %s - Input: \"%s\", \"%s\", %zu - Expected: %d, Got: %d\n", 
               test_num, description, s1, s2, n, expected, result);
        return 0;
    }
}

int main(void)
{
    int passed = 0;
    int total = 0;
    
    printf("ft_strncmp\n");
    
    // Test 1: Equal strings, full comparison
    passed += run_test(++total, "Equal strings, full comparison", "Hello", "Hello", 5);
    
    // Test 2: Equal strings, partial comparison
    passed += run_test(++total, "Equal strings, partial comparison", "Hello", "Hello", 3);
    
    // Test 3: Different strings, first different character
    passed += run_test(++total, "Different strings, first different character", "Apple", "Banana", 1);
    
    // Test 4: Different strings, third different character
    passed += run_test(++total, "Different strings, third different character", "Hello", "Healo", 5);
    
    // Test 5: First string longer, same prefix
    passed += run_test(++total, "First string longer, same prefix", "Hello World", "Hello", 10);
    return (passed == total) ? 0 : 1;
}
