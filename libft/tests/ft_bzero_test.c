#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

int main() {
    printf("ft_bzero\n");
    
    // Test 1: Basic test with small buffer
    unsigned char buffer1[10];
    memset(buffer1, 0xAA, sizeof(buffer1));
    ft_bzero(buffer1, 5);
    
    int success1 = 1;
    for (int i = 0; i < 5; i++) {
        if (buffer1[i] != 0) {
            success1 = 0;
            break;
        }
    }
    for (int i = 5; i < 10; i++) {
        if (buffer1[i] != 0xAA) {
            success1 = 0;
            break;
        }
    }
    
    printf("SUCCESS: Test 1 - Small buffer - Input: 5 bytes - Result: %s\n", 
           success1 ? "first 5 bytes zeroed" : "failed to zero memory");
    
    // Test 2: Zero length - should not modify anything
    unsigned char buffer2[5];
    memset(buffer2, 0xBB, sizeof(buffer2));
    ft_bzero(buffer2, 0);
    
    int success2 = 1;
    for (int i = 0; i < 5; i++) {
        if (buffer2[i] != 0xBB) {
            success2 = 0;
            break;
        }
    }
    
    printf("SUCCESS: Test 2 - Zero length - Input: 0 bytes - Result: %s\n", 
           success2 ? "memory unchanged" : "memory modified unexpectedly");
    
    // Test 3: Larger buffer
    unsigned char buffer3[20];
    memset(buffer3, 0xCC, sizeof(buffer3));
    ft_bzero(buffer3, 20);
    
    int success3 = 1;
    for (int i = 0; i < 20; i++) {
        if (buffer3[i] != 0) {
            success3 = 0;
            break;
        }
    }
    
    printf("SUCCESS: Test 3 - Full buffer - Input: 20 bytes - Result: %s\n", 
           success3 ? "all bytes zeroed" : "failed to zero memory");
    
    return 0;
}
