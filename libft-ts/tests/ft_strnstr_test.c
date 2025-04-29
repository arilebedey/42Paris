#include <stdio.h>
#include <bsd/string.h>
#include "../libft/libft.h"

void test_strnstr(const char *haystack, const char *needle, size_t len, int test_num, const char *test_desc)
{
    char *expected = strnstr(haystack, needle, len);
    char *result = ft_strnstr(haystack, needle, len);
    
    // For NULL pointer results, we need special handling to avoid comparing addresses
    if ((expected == NULL && result == NULL) || 
        (expected != NULL && result != NULL && strcmp(expected, result) == 0))
    {
        printf("SUCCESS: Test %d - %s - Haystack: \"%s\", Needle: \"%s\", Len: %zu\n", 
               test_num, test_desc, haystack, needle, len);
    }
    else
    {
        printf("FAILURE: Test %d - %s - Haystack: \"%s\", Needle: \"%s\", Len: %zu - ", 
               test_num, test_desc, haystack, needle, len);
        
        if (expected == NULL)
            printf("Expected: NULL, ");
        else
            printf("Expected: \"%s\", ", expected);
            
        if (result == NULL)
            printf("Result: NULL\n");
        else
            printf("Result: \"%s\"\n", result);
    }
}

int main(void)
{
    printf("ft_strnstr\n");
    
    // Test 1: Basic substring search
    test_strnstr("Hello, world!", "world", 13, 1, "Basic substring search");
    
    // Test 2: Empty needle (should return haystack)
    test_strnstr("Hello, world!", "", 13, 2, "Empty needle");
    
    // Test 3: Needle not in haystack
    test_strnstr("Hello, world!", "universe", 13, 3, "Needle not in haystack");
    
    // Test 4: Limit len - needle exists but after len
    test_strnstr("Hello, world!", "world", 7, 4, "Needle exists but after len");
    
    // Test 5: Limit len - needle partially within len
    test_strnstr("Hello, world!", "world", 9, 5, "Needle partially within len");
    
    // Test 6: Multiple occurrences - should find first
    test_strnstr("lololol", "lol", 7, 6, "Multiple occurrences - first");
    
    // Test 7: Needle at the beginning
    test_strnstr("Needle in a haystack", "Needle", 20, 7, "Needle at beginning");
    
    // Test 8: Needle at the end, just within len
    test_strnstr("Finding a needle", "needle", 16, 8, "Needle at the end");
    
    // Test 9: Case sensitivity
    test_strnstr("Case Sensitive", "case", 13, 9, "Case sensitivity");
    
    // Test 10: Exact length match
    test_strnstr("exact", "exact", 5, 10, "Exact length match");
    
    // Test 11: Length longer than haystack
    test_strnstr("short", "short", 10, 11, "Length longer than haystack");
    
    // Test 12: Empty haystack
    test_strnstr("", "anything", 10, 12, "Empty haystack");
    
    return 0;
}
