#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int test_strrchr(const char *s, int c, int test_num, const char *desc)
{
    char *ft_result = ft_strrchr(s, c);
    char *std_result = strrchr(s, c);
    
    int success = (ft_result == std_result) || 
                 ((ft_result && std_result) && (ft_result - s == std_result - s));
    
    printf("%s: Test %d - %s - Input: \"%s\", Char: '%c'\n", 
           success ? "SUCCESS" : "FAILURE", test_num, desc, s, c);
    
    return success;
}

int main(void)
{
    int tests_passed = 0;
    int total_tests = 0;
    
    printf("ft_strrchr\n");
    
    // Test 1: Basic character search in middle of string
    total_tests++;
    tests_passed += test_strrchr("Hello World", 'o', 1, "Basic character search");
    
    // Test 2: Character not in string
    total_tests++;
    tests_passed += test_strrchr("Hello World", 'z', 2, "Character not in string");
    
    // Test 3: Last character in string
    total_tests++;
    tests_passed += test_strrchr("Hello World", 'd', 3, "Last character in string");
    
    // Test 4: First character in string
    total_tests++;
    tests_passed += test_strrchr("Hello World", 'H', 4, "First character in string");
    
    // Test 5: Null terminator
    total_tests++;
    tests_passed += test_strrchr("Hello World", '\0', 5, "Null terminator");
    
    // Test 6: Empty string
    total_tests++;
    tests_passed += test_strrchr("", 'a', 6, "Empty string");
    
    // Test 7: Empty string with null terminator
    total_tests++;
    tests_passed += test_strrchr("", '\0', 7, "Empty string with null terminator");
    
    // Test 8: Multiple occurrences
    total_tests++;
    tests_passed += test_strrchr("Hello World Hello", 'o', 8, "Multiple occurrences");
    
    // Test 9: Special character
    total_tests++;
    tests_passed += test_strrchr("Hello\tWorld", '\t', 9, "Special character");
    
    // Test 10: Numeric character as int
    total_tests++;
    tests_passed += test_strrchr("H3llo Wor1d", 49, 10, "Numeric character as int");
    
    return (0);
}
