#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

// ANSI color codes for output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

// Simple macro to print success/failure
#define TEST_RESULT(condition, test_num, test_name, input, result) \
    if (condition) \
        printf("%sSUCCESS: Test %d - %s - Input: %s - Result: %d%s\n", \
               GREEN, test_num, test_name, input, result, RESET); \
    else \
        printf("%sFAILURE: Test %d - %s - Input: %s - Result: %d%s\n", \
               RED, test_num, test_name, input, result, RESET);

int main(void)
{
    int result;
    char buffer[256];
    
    printf("\nft_printf\n");
    
    // Test %c format
    result = ft_printf("%c\n", 'A');
    TEST_RESULT(result == 2, 1, "Basic character", "'A'", result);
    
    result = ft_printf("%c\n", 'Z');
    TEST_RESULT(result == 2, 2, "Single character", "'Z'", result);
    
    // Test %s format
    result = ft_printf("%s\n", "Hello");
    TEST_RESULT(result == 6, 3, "Basic string", "\"Hello\"", result);
    
    result = ft_printf("\n", "");
    TEST_RESULT(result == 1, 4, "Empty string", "\"\"", result);
    
    // Test %d and %i format
    result = ft_printf("%d\n", 42);
    TEST_RESULT(result == 3, 5, "Basic decimal", "42", result);
    
    result = ft_printf("%i\n", -42);
    TEST_RESULT(result == 4, 6, "Negative integer", "-42", result);
    
    sprintf(buffer, "%d", INT_MIN);
    result = ft_printf("%d\n", INT_MIN);
    TEST_RESULT(result == (int)(12), 7, "Integer MIN", buffer, result);
    
    sprintf(buffer, "%d", INT_MAX);
    result = ft_printf("%d\n", INT_MAX);
    TEST_RESULT(result == (int)(11), 8, "Integer MAX", buffer, result);
    
    // Test %u format
    result = ft_printf("%u\n", 42);
    TEST_RESULT(result == 3, 9, "Basic unsigned", "42", result);
    
    sprintf(buffer, "%u", UINT_MAX);
    result = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    TEST_RESULT(result == (int)(11 + strlen(buffer)), 10, "Unsigned MAX", buffer, result);
    
    // Test %x and %X format
    result = printf("%x\n", 0xabc);
    result = ft_printf("%x\n", 0xabc);
    TEST_RESULT(result == 4, 11, "Hex lowercase", "0xabc", result);
    
    result = ft_printf("%X\n", 0xABC);
    TEST_RESULT(result == 4, 12, "Hex uppercase", "0xABC", result);
    
    sprintf(buffer, "%x", 0);
    result = ft_printf("%x\n", 0);
    TEST_RESULT(result == 2, 13, "Hex zero", "0", result);
    
    // Test %p format
    int number = 42;
    void *ptr = &number;
    result = ft_printf("Pointer: %p\n", ptr);
    TEST_RESULT(result > 10, 14, "Basic pointer", "address", result);
    
    result = ft_printf("NULL pointer: %p\n", NULL);
    TEST_RESULT(result > 14, 15, "NULL pointer", "NULL", result);
    
    // Test %% format
    result = ft_printf("%%\n");
    TEST_RESULT(result == 2, 16, "Percent sign", "\"%\"", result);
    
    // Mixed format specifiers
    result = ft_printf("Mixed: %c %s %d %x %p %%\n", 'Z', "test", -42, 0xdef, ptr);
    TEST_RESULT(result > 20, 17, "Mixed formats", "multiple values", result);
    
    // Test with no format specifiers
    result = ft_printf("No specifiers here\n");
    TEST_RESULT(result == 19, 18, "No specifiers", "plain text", result);
    
    // Test concatenated format specifiers
    result = ft_printf("%d%d%d\n", 1, 2, 3);
    TEST_RESULT(result == 4, 19, "Concatenated formats", "123", result);
    
    // NULL string test - handle carefully
    char *null_string = NULL;
    result = ft_printf("NULL string: %s\n", null_string);
    TEST_RESULT(result > 0, 20, "NULL string", "NULL", result);
    
    // Test with consecutive identical format specifiers
    result = ft_printf("%c%c%c\n", '1', '2', '3');
    TEST_RESULT(result == 4, 21, "Consecutive characters", "'1''2''3'", result);
    
    // Test edge cases for integers
    result = ft_printf("%d %d %d\n", 0, INT_MIN, INT_MAX);
    TEST_RESULT(result > 0, 22, "Integer edge cases", "0, MIN, MAX", result);
    
    // Test multiline output
    result = ft_printf("Line1\nLine2\nLine3\n");
    TEST_RESULT(result == 18, 23, "Multiline output", "\"Line1\\nLine2\\nLine3\\n\"", result);
    
    return (0);
}
