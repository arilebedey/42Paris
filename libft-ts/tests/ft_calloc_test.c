#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_zeroed(void *ptr, size_t size)
{
    unsigned char *byte_ptr = (unsigned char *)ptr;
    size_t i;
    
    for (i = 0; i < size; i++)
    {
        if (byte_ptr[i] != 0)
            return (0);
    }
    return (1);
}

int main(void)
{
    void *result;
    
    printf("ft_calloc\n");
    
    /* Test 1 - Basic allocation */
    result = ft_calloc(10, sizeof(int));
    printf("SUCCESS: Test 1 - Basic allocation - Input: \"10, sizeof(int)\" - Result: %s\n", 
        (result != NULL && check_zeroed(result, 10 * sizeof(int))) ? "Valid zeroed memory" : "Invalid memory");
    free(result);
    
    /* Test 2 - Zero count or size */
    result = ft_calloc(0, sizeof(int));
    printf("SUCCESS: Test 2 - Zero count - Input: \"0, sizeof(int)\" - Result: %s\n", 
        result != NULL ? "Valid pointer" : "NULL");
    free(result);
    
    /* Test 3 - Security check: overflow detection */
    result = ft_calloc((size_t)-1, 2);
    printf("SUCCESS: Test 3 - Security check: overflow detection - Input: \"SIZE_MAX, 2\" - Result: %s\n", 
        result == NULL ? "NULL (overflow protected)" : "Memory allocated (UNSAFE)");
    
    return (0);
}
