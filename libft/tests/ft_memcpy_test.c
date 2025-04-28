#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main(void)
{
    printf("ft_memcpy\n");
    
    // Test 1: Basic string copy
    {
        char src[] = "Hello, World!";
        char dst[20] = {0};
        char expected[20] = {0};
        
        ft_memcpy(dst, src, strlen(src) + 1);
        memcpy(expected, src, strlen(src) + 1);
        
        if (strcmp(dst, expected) == 0)
            printf("SUCCESS: Test 1 - Basic string copy - Input: \"%s\" - Result: \"%s\"\n", src, dst);
        else
            printf("FAILURE: Test 1 - Basic string copy - Input: \"%s\" - Expected: \"%s\", Got: \"%s\"\n", src, expected, dst);
    }
    
    // Test 2: Copy integer array
    {
        int src[] = {1, 2, 3, 4, 5};
        int dst[5] = {0};
        int expected[5] = {0};
        int size = sizeof(src);
        
        ft_memcpy(dst, src, size);
        memcpy(expected, src, size);
        
        int success = 1;
        for (int i = 0; i < 5; i++) {
            if (dst[i] != expected[i]) {
                success = 0;
                break;
            }
        }
        
        if (success)
            printf("SUCCESS: Test 2 - Integer array copy - Input: [1,2,3,4,5] - Result: Correct copy\n");
        else
            printf("FAILURE: Test 2 - Integer array copy - Input: [1,2,3,4,5] - Result: Incorrect copy\n");
    }
    
    // Test 3: Copy with zero length
    {
        char src[] = "Test";
        char dst[10] = "Original";
        char expected[10] = "Original";
        
        ft_memcpy(dst, src, 0);
        memcpy(expected, src, 0);
        
        if (strcmp(dst, expected) == 0)
            printf("SUCCESS: Test 3 - Zero length copy - Input: size=0 - Result: Unchanged destination\n");
        else
            printf("FAILURE: Test 3 - Zero length copy - Input: size=0 - Expected unchanged, Got: \"%s\"\n", dst);
    }
    
    // Test 4: Copy part of string
    {
        char src[] = "Hello, World!";
        char dst[10] = {0};
        char expected[10] = {0};
        
        ft_memcpy(dst, src, 5);
        memcpy(expected, src, 5);
        
        int success = 1;
        for (int i = 0; i < 5; i++) {
            if (dst[i] != expected[i]) {
                success = 0;
                break;
            }
        }
        
        if (success)
            printf("SUCCESS: Test 4 - Partial string copy - Input: \"%s\" (5 bytes) - Result: \"%.5s\"\n", src, dst);
        else
            printf("FAILURE: Test 4 - Partial string copy - Input: \"%s\" (5 bytes) - Result incorrect\n", src);
    }
    return 0;
}
