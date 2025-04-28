#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

void run_test(int test_num, const char *description, int result, int expected)
{
    if (result == expected)
        printf("SUCCESS: Test %d - %s\n", test_num, description);
    else
        printf("FAILURE: Test %d - %s - Expected: %d, Got: %d\n", test_num, description, expected, result);
}

void run_string_test(int test_num, const char *description, const char *dst, const char *expected)
{
    if (strcmp(dst, expected) == 0)
        printf("SUCCESS: Test %d - %s\n", test_num, description);
    else
        printf("FAILURE: Test %d - %s - Expected: \"%s\", Got: \"%s\"\n", 
               test_num, description, expected, dst);
}

void run_memory_test(int test_num, const char *description, const void *dst, 
                     const void *expected, size_t size)
{
    if (memcmp(dst, expected, size) == 0)
        printf("SUCCESS: Test %d - %s\n", test_num, description);
    else
    {
        printf("FAILURE: Test %d - %s - Memory contents differ\n", test_num, description);
        // Print hex values for debugging
        unsigned char *d = (unsigned char *)dst;
        unsigned char *e = (unsigned char *)expected;
        printf("  Expected: ");
        for (size_t i = 0; i < size; i++)
            printf("%02x ", e[i]);
        printf("\n  Got:      ");
        for (size_t i = 0; i < size; i++)
            printf("%02x ", d[i]);
        printf("\n");
    }
}

int main(void)
{
    printf("ft_memmove\n");
    
    // Test 1: Basic non-overlapping copy
    {
        char src[] = "Hello, World!";
        char dst[20] = {0};
        char expected[20] = "Hello, World!";
        
        ft_memmove(dst, src, strlen(src) + 1);
        run_string_test(1, "Basic non-overlapping copy", dst, expected);
    }
    
    // Test 4: Empty string copy
    {
        char src[] = "";
        char dst[5] = "Test";
        char expected[5] = "Test";
        
        ft_memmove(dst, src, 0);
        run_string_test(4, "Empty string copy (len = 0)", dst, expected);
    }
    
    // Test 5: Copy zero bytes
    {
        char src[] = "Source";
        char dst[] = "Destination";
        char expected[] = "Destination";
        
        ft_memmove(dst, src, 0);
        run_string_test(5, "Copy zero bytes", dst, expected);
    }
    
    // Test 6: Copy to same destination
    {
        char str[] = "Test string";
        char expected[] = "Test string";
        
        ft_memmove(str, str, strlen(str) + 1);
        run_string_test(6, "Copy to same destination", str, expected);
    }
    
    // Test 7: Copy binary data with null bytes
    {
        unsigned char src[] = {0x10, 0x20, 0x00, 0x30, 0x40};
        unsigned char dst[10] = {0};
        unsigned char expected[] = {0x10, 0x20, 0x00, 0x30, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00};
        
        ft_memmove(dst, src, 5);
        run_memory_test(7, "Copy binary data with null bytes", dst, expected, 10);
    }
    
    // Test 8: Large memory block copy
    {
        size_t size = 1024;
        char *src = (char *)malloc(size);
        char *dst = (char *)malloc(size);
        char *expected = (char *)malloc(size);
        
        if (src && dst && expected) {
            // Fill with pattern
            for (size_t i = 0; i < size; i++) {
                src[i] = i % 256;
                expected[i] = i % 256;
            }
            
            ft_memmove(dst, src, size);
            run_memory_test(8, "Large memory block copy", dst, expected, size);
            
            free(src);
            free(dst);
            free(expected);
        } else {
            printf("FAILURE: Test 8 - Large memory block copy - Memory allocation failed\n");
        }
    }
    
    // Test 9: Complex overlapping case - moving memory upward in small buffer
    {
        char buffer[10] = "abcdef";
        char expected[10] = "aabcdef";
        
        ft_memmove(buffer + 1, buffer, 6);
        run_memory_test(9, "Complex overlapping case - moving memory upward", 
                      buffer, expected, 10);
    }

    return 0;
}
