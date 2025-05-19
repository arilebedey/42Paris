#include <stdio.h>
#include "ft_printf.h"

int main() {
    printf("PRINT_F\n");
    // Test 1: Using "%%%" format specifier
    printf("Test 1 - %%%%%%\\n\n");
	printf("String printed: ");
    int result1 = printf("%%%\n");
    printf("Characters printed: %d\n\n", result1);
    
    // Test 2: Using "%z" format specifier
    printf("Test 2 - Using %%z\\n\n");
	printf("String printed: ");
    int result2 = printf("%z\n");
    printf("Characters printed: %d\n\n", result2);
    
    // Test 3: Using "%o" format specifier (octal, actually valid)
    printf("Test 3 - Using %%\\n\n");
	printf("String printed: ");
    int result3 = printf("%\n");
    printf("Characters printed: %d\n\n", result3);
    
    
    printf("FT_PRINT_F\n");
    // Test 1: Using "%%%" format specifier
    printf("Test 1 - %%%%%%\\n\n");
	ft_printf("String printed: ");
    result1 = ft_printf("%%%\n");
    ft_printf("Characters printed: %d\n\n", result1);
    
    // Test 2: Using "%z" format specifier
    printf("Test 2 - Using %%z\\n\n");
	ft_printf("String printed: ");
    result2 = ft_printf("%z\n");
    ft_printf("Characters printed: %d\n\n", result2);
    
    // Test 3: Using "%o" format specifier (octal, actually valid)
    printf("Test 3 - Using %%\\n\n");
	ft_printf("String printed: ");
    result3 = ft_printf("%\n");
    ft_printf("Characters printed: %d\n\n", result3);
    
    return 0;
}
