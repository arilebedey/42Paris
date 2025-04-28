#include "../libft/libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <stdbool.h>

void test_strlcat(const char *dst_initial, const char *src, size_t size, const char *test_name)
{
    // Prepare buffers for the standard function and our function
    char dst_std[100];
    char dst_ft[100];
    
    // Initialize buffers with the initial value
    strcpy(dst_std, dst_initial);
    strcpy(dst_ft, dst_initial);
    
    // Call both functions
    size_t result_std = strlcat(dst_std, src, size);
    size_t result_ft = ft_strlcat(dst_ft, src, size);
    
    // Compare results
    bool length_match = (result_std == result_ft);
    bool content_match = (strcmp(dst_std, dst_ft) == 0);
    
    // Print results in required format
    if (length_match && content_match) {
        printf("SUCCESS: %s - Dst: \"%s\", Src: \"%s\", Size: %zu - Result: %zu\n", 
               test_name, dst_initial, src, size, result_ft);
    } else {
        printf("FAILURE: %s - Dst: \"%s\", Src: \"%s\", Size: %zu\n", 
               test_name, dst_initial, src, size);
        printf("  Expected: result=%zu, dst=\"%s\"\n", result_std, dst_std);
        printf("  Got: result=%zu, dst=\"%s\"\n", result_ft, dst_ft);
    }
}

int main(void)
{
    printf("ft_strlcat\n");
    
    // Test 1: Basic concatenation with enough space
    test_strlcat("Hello ", "world!", 20, "Test 1 - Basic concatenation");
    
    // Test 2: Concatenation with exact size (dst + src + null terminator)
    test_strlcat("Hello ", "world!", 12, "Test 2 - Exact size");
    
    // Test 3: Concatenation with limited size (truncation)
    test_strlcat("Hello ", "world!", 10, "Test 3 - Truncation");
    
    // Test 4: Empty destination string
    test_strlcat("", "Test", 10, "Test 4 - Empty destination");
    
    return 0;
}
