#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

void print_test_result(int test_num, const char *description, int result)
{
    if (result)
        printf("SUCCESS: Test %d - %s\n", test_num, description);
    else
        printf("FAILURE: Test %d - %s\n", test_num, description);
}

int test_memset_buffer(int value, size_t len)
{
    // Create two identical buffers
    unsigned char buf1[30];
    unsigned char buf2[30];
    
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

int test_empty_length()
{
    unsigned char buf1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned char buf2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // The compiler is warning about potential argument transposition
    // But we really do want to set 0 bytes here to test that behavior
    ft_memset(buf1, 'A', 0);
    
    // Use a different approach to avoid compiler warning
    // Simply don't call memset when length is 0
    // The buffers should remain identical
    
    for (size_t i = 0; i < 10; i++)
    {
        if (buf1[i] != buf2[i])
            return 0;
    }
    return 1;
}

int test_null_ptr()
{
    void *result = ft_memset(NULL, 'A', 10);
    return result == NULL;
}

int test_return_value()
{
    unsigned char buf[10];
    void *result = ft_memset(buf, 'A', 10);
    return result == buf;
}

int main(void)
{
    printf("ft_memset\n");
    
    // Test 1: Regular character value
    print_test_result(1, "Regular character value ('A')", test_memset_buffer('A', 15));
    
    // Test 2: Zero value
    print_test_result(2, "Zero value (0)", test_memset_buffer(0, 15));
    
    // Test 3: Value truncated to unsigned char (> 255)
    print_test_result(3, "Value above 255 (300)", test_memset_buffer(300, 15));
    
    // Test 4: Small length
    print_test_result(4, "Small length (1 byte)", test_memset_buffer('B', 1));
    
    // Test 5: Large length
    print_test_result(5, "Large length (30 bytes)", test_memset_buffer('C', 30));
    
    // Test 6: Zero length (should not modify the memory)
    print_test_result(6, "Zero length (0 bytes)", test_empty_length());
    
    // Test 7: NULL pointer (should return NULL)
    print_test_result(7, "NULL pointer", test_null_ptr());
    
    // Test 8: Return value (should return the original pointer)
    print_test_result(8, "Return value check", test_return_value());

    return 0;
}
