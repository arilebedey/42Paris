#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

// Test function 1: Convert to uppercase based on index
void test_uppercase_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

// Test function 2: Set char to index value (as ASCII)
void test_set_to_index(unsigned int i, char *c)
{
    *c = i + '0';
}

// Test function 3: Set all chars to '*'
void test_set_to_asterisk(unsigned int i, char *c)
{
    (void)i;
    *c = '*';
}

// Test function 4: Add index to ASCII value
void test_add_index(unsigned int i, char *c)
{
    *c = *c + i;
}

// Test function that does nothing, just to test null behavior
void test_do_nothing(unsigned int i, char *c)
{
    (void)i;
    (void)c;
}

int main(void)
{
    printf("ft_striteri\n");
    
    // Test 1 - Convert even index characters to uppercase
    char test1[] = "abcdefgh";
    char expected1[] = "AbCdEfGh";
    ft_striteri(test1, test_uppercase_even);
    if (strcmp(test1, expected1) == 0)
        printf("SUCCESS: Test 1 - Convert even index chars to uppercase - Input: \"abcdefgh\" - Result: \"%s\"\n", test1);
    else
        printf("FAILURE: Test 1 - Convert even index chars to uppercase - Input: \"abcdefgh\" - Result: \"%s\", Expected: \"%s\"\n", test1, expected1);
    
    // Test 2 - Set each character to its index value
    char test2[] = "hello";
    char expected2[] = "01234";
    ft_striteri(test2, test_set_to_index);
    if (strcmp(test2, expected2) == 0)
        printf("SUCCESS: Test 2 - Set chars to index value - Input: \"hello\" - Result: \"%s\"\n", test2);
    else
        printf("FAILURE: Test 2 - Set chars to index value - Input: \"hello\" - Result: \"%s\", Expected: \"%s\"\n", test2, expected2);
    
    // Test 3 - Set all characters to asterisk
    char test3[] = "test";
    char expected3[] = "****";
    ft_striteri(test3, test_set_to_asterisk);
    if (strcmp(test3, expected3) == 0)
        printf("SUCCESS: Test 3 - Set all chars to asterisk - Input: \"test\" - Result: \"%s\"\n", test3);
    else
        printf("FAILURE: Test 3 - Set all chars to asterisk - Input: \"test\" - Result: \"%s\", Expected: \"%s\"\n", test3, expected3);
    
    // Test 4 - Add index to ASCII value of each character
    char test4[] = "aaaaa";
    char expected4[] = "abcde";
    ft_striteri(test4, test_add_index);
    if (strcmp(test4, expected4) == 0)
        printf("SUCCESS: Test 4 - Add index to ASCII value - Input: \"aaaaa\" - Result: \"%s\"\n", test4);
    else
        printf("FAILURE: Test 4 - Add index to ASCII value - Input: \"aaaaa\" - Result: \"%s\", Expected: \"%s\"\n", test4, expected4);
    
    // Test 5 - Empty string
    char test5[] = "";
    char expected5[] = "";
    ft_striteri(test5, test_set_to_asterisk);
    if (strcmp(test5, expected5) == 0)
        printf("SUCCESS: Test 5 - Empty string - Input: \"\" - Result: \"%s\"\n", test5);
    else
        printf("FAILURE: Test 5 - Empty string - Input: \"\" - Result: \"%s\", Expected: \"%s\"\n", test5, expected5);
    
    // Test 6 - Single character
    char test6[] = "x";
    char expected6[] = "*";
    ft_striteri(test6, test_set_to_asterisk);
    if (strcmp(test6, expected6) == 0)
        printf("SUCCESS: Test 6 - Single character - Input: \"x\" - Result: \"%s\"\n", test6);
    else
        printf("FAILURE: Test 6 - Single character - Input: \"x\" - Result: \"%s\", Expected: \"%s\"\n", test6, expected6);
    
    // Test 7 - Function that does nothing
    char test7[] = "unchanged";
    char expected7[] = "unchanged";
    ft_striteri(test7, test_do_nothing);
    if (strcmp(test7, expected7) == 0)
        printf("SUCCESS: Test 7 - Function does nothing - Input: \"unchanged\" - Result: \"%s\"\n", test7);
    else
        printf("FAILURE: Test 7 - Function does nothing - Input: \"unchanged\" - Result: \"%s\", Expected: \"%s\"\n", test7, expected7);
    
    // Test 8 - String with special characters
    char test8[] = "!@#$%";
    char expected8[] = "*****";
    ft_striteri(test8, test_set_to_asterisk);
    if (strcmp(test8, expected8) == 0)
        printf("SUCCESS: Test 8 - String with special chars - Input: \"!@#$%%\" - Result: \"%s\"\n", test8);
    else
        printf("FAILURE: Test 8 - String with special chars - Input: \"!@#$%%\" - Result: \"%s\", Expected: \"%s\"\n", test8, expected8);
    
    // Test 9 - String with spaces
    char test9[] = "a b c";
    char expected9[] = "a b c";
    ft_striteri(test9, test_do_nothing);
    if (strcmp(test9, expected9) == 0)
        printf("SUCCESS: Test 9 - String with spaces - Input: \"a b c\" - Result: \"%s\"\n", test9);
    else
        printf("FAILURE: Test 9 - String with spaces - Input: \"a b c\" - Result: \"%s\", Expected: \"%s\"\n", test9, expected9);
    
    return (0);
}
