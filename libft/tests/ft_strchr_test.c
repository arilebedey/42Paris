#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main(void)
{
    printf("ft_strchr\n");
    
    // Test 1: Basic character in middle of string
    const char *test1 = "Hello World";
    char to_find1 = 'W';
    char *result1 = ft_strchr(test1, to_find1);
    char *expected1 = strchr(test1, to_find1);
    printf("%s: Test 1 - Basic character in middle of string - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result1 == expected1) ? "SUCCESS" : "FAILURE", test1, to_find1, (void *)result1, (void *)expected1);
    
    // Test 2: Character at beginning of string
    const char *test2 = "Hello World";
    char to_find2 = 'H';
    char *result2 = ft_strchr(test2, to_find2);
    char *expected2 = strchr(test2, to_find2);
    printf("%s: Test 2 - Character at beginning of string - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result2 == expected2) ? "SUCCESS" : "FAILURE", test2, to_find2, (void *)result2, (void *)expected2);
    
    // Test 3: Character at end of string
    const char *test3 = "Hello World";
    char to_find3 = 'd';
    char *result3 = ft_strchr(test3, to_find3);
    char *expected3 = strchr(test3, to_find3);
    printf("%s: Test 3 - Character at end of string - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result3 == expected3) ? "SUCCESS" : "FAILURE", test3, to_find3, (void *)result3, (void *)expected3);
    
    // Test 4: Null terminator
    const char *test4 = "Hello World";
    char to_find4 = '\0';
    char *result4 = ft_strchr(test4, to_find4);
    char *expected4 = strchr(test4, to_find4);
    printf("%s: Test 4 - Null terminator - Input: \"%s\", searching '\\0' - Result: %p (Expected: %p)\n", 
        (result4 == expected4) ? "SUCCESS" : "FAILURE", test4, (void *)result4, (void *)expected4);
    
    // Test 5: Character not in string
    const char *test5 = "Hello World";
    char to_find5 = 'z';
    char *result5 = ft_strchr(test5, to_find5);
    char *expected5 = strchr(test5, to_find5);
    printf("%s: Test 5 - Character not in string - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result5 == expected5) ? "SUCCESS" : "FAILURE", test5, to_find5, (void *)result5, (void *)expected5);
    
    // Test 6: Empty string
    const char *test6 = "";
    char to_find6 = 'a';
    char *result6 = ft_strchr(test6, to_find6);
    char *expected6 = strchr(test6, to_find6);
    printf("%s: Test 6 - Empty string - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result6 == expected6) ? "SUCCESS" : "FAILURE", test6, to_find6, (void *)result6, (void *)expected6);
    
    // Test 7: Multiple occurrences (should return first)
    const char *test7 = "Hello World Hello";
    char to_find7 = 'l';
    char *result7 = ft_strchr(test7, to_find7);
    char *expected7 = strchr(test7, to_find7);
    printf("%s: Test 7 - Multiple occurrences - Input: \"%s\", searching '%c' - Result: %p (Expected: %p)\n", 
        (result7 == expected7) ? "SUCCESS" : "FAILURE", test7, to_find7, (void *)result7, (void *)expected7);
    
    // Test 8: Integer cast to char (ASCI)
    const char *test8 = "Hello World";
    int to_find8 = 87; // ASCII for 'W'
    char *result8 = ft_strchr(test8, to_find8);
    char *expected8 = strchr(test8, to_find8);
    printf("%s: Test 8 - Integer cast to char - Input: \"%s\", searching %d - Result: %p (Expected: %p)\n", 
        (result8 == expected8) ? "SUCCESS" : "FAILURE", test8, to_find8, (void *)result8, (void *)expected8);
    
    // Test 9: Integer > 127 (extended ASCII) but % 256 is present
    const char *test9 = "Hello World";
    int to_find9 = 87 + 256; // 'W' + 256, should still find 'W'
    char *result9 = ft_strchr(test9, to_find9);
    char *expected9 = strchr(test9, to_find9);
    printf("%s: Test 9 - Character with high integer value - Input: \"%s\", searching %d - Result: %p (Expected: %p)\n", 
        (result9 == expected9) ? "SUCCESS" : "FAILURE", test9, to_find9, (void *)result9, (void *)expected9);

    return (0);
}
