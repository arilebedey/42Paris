#include <stdio.h>
#include <string.h>
#include "libft.h"

int test_memset_int_array(int value)
{
    // Create two identical arrays
    int arr1[5];
    int arr2[5];
    
    // Apply ft_memset and standard memset
    ft_memset(arr1, value, sizeof(arr1));
    memset(arr2, value, sizeof(arr2));
    
    // Compare results
    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] != arr2[i])
            return 0; // Failure
    }
    return 1; // Success
}

int test_memset_char_array(int value, size_t len)
{
    // Create two identical buffers
    char buf1[20];
    char buf2[20];
    
    // Apply ft_memset and standard memset
    ft_memset(buf1, value, len);
    memset(buf2, value, len);
    
    // Compare results
    for (size_t i = 0; i < len; i++)
    {
        if (buf1[i] != buf2[i])
            return 0; // Failure
    }
    return 1; // Success
}

int main(void)
{
    printf("ft_memset\n");
    
    // Test 1: Regular value (below 256)
    if (test_memset_int_array(65))
        printf("SUCCESS: Test 1 - Regular value (65)\n");
    else
        printf("FAIL: Test 1 - Regular value (65)\n");
    
    // Test 2: Value above 255
    if (test_memset_int_array(2000))
        printf("SUCCESS: Test 2 - Value above 255 (2000)\n");
    else
        printf("FAIL: Test 2 - Value above 255 (2000)\n");
    
    // Test 3: Zero value
    if (test_memset_int_array(0))
        printf("SUCCESS: Test 3 - Zero value\n");
    else
        printf("FAIL: Test 3 - Zero value\n");
    
    // Test 4: Character buffer (regular value)
    if (test_memset_char_array('A', 10))
        printf("SUCCESS: Test 4 - Character buffer with 'A'\n");
    else
        printf("FAIL: Test 4 - Character buffer with 'A'\n");
    
    // Test 5: Character buffer (value above 255)
    if (test_memset_char_array(2000, 10))
        printf("SUCCESS: Test 5 - Character buffer with value above 255\n");
    else
        printf("FAIL: Test 5 - Character buffer with value above 255\n");
    return 0;
}
