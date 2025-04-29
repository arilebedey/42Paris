#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_substr(char const *s, unsigned int start, size_t len, char *expected, int test_num, char *test_name)
{
    char *result = ft_substr(s, start, len);
    int success = (strcmp(result, expected) == 0);
    
    printf("%s: Test %d - %s - Input: \"%s\", start=%u, len=%zu - Result: \"%s\"\n", 
           success ? "SUCCESS" : "FAILURE", test_num, test_name, s, start, len, result);
    
    free(result);
}

int main(void)
{
    printf("ft_substr\n");
    
    // Test 1: Basic substring from middle
    test_substr("Hello, world!", 7, 5, "world", 1, "Basic substring from middle");
    
    // Test 2: Substring from start
    test_substr("Hello, world!", 0, 5, "Hello", 2, "Substring from start");
    
    // Test 3: Substring to end
    test_substr("Hello, world!", 7, 6, "world!", 3, "Substring to end");
    
    // Test 4: Empty string
    test_substr("", 0, 5, "", 4, "Empty string");
    
    // Test 5: Start beyond string length
    test_substr("Hello", 10, 5, "", 5, "Start beyond string length");
    
    // Test 6: Zero length
    test_substr("Hello, world!", 7, 0, "", 6, "Zero length");
    
    // Test 10: Full string
    test_substr("Complete", 0, 8, "Complete", 7, "Full string");
    
    return (0);
}
