#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("ft_isascii\n");
    
    /* Test 1 - Value just below valid ASCII range (-1) */
    int result1 = ft_isascii(-1);
    printf("%s: Test 1 - Value just below valid ASCII range - Input: \"%d\" - Result: %d\n", 
           result1 == 0 ? "SUCCESS" : "FAILURE", -1, result1);
    
    /* Test 2 - Lowest valid ASCII value (0) */
    int result2 = ft_isascii(0);
    printf("%s: Test 2 - Lowest valid ASCII value - Input: \"%d\" - Result: %d\n", 
           result2 == 1 ? "SUCCESS" : "FAILURE", 0, result2);
    
    /* Test 3 - Highest valid ASCII value (127) */
    int result3 = ft_isascii(127);
    printf("%s: Test 3 - Highest valid ASCII value - Input: \"%d\" - Result: %d\n", 
           result3 == 1 ? "SUCCESS" : "FAILURE", 127, result3);
    
    /* Test 4 - Value just above valid ASCII range (128) */
    int result4 = ft_isascii(128);
    printf("%s: Test 4 - Value just above valid ASCII range - Input: \"%d\" - Result: %d\n", 
           result4 == 0 ? "SUCCESS" : "FAILURE", 128, result4);
    
    /* Test 5 - Large negative value */
    int result5 = ft_isascii(-1000);
    printf("%s: Test 5 - Large negative value - Input: \"%d\" - Result: %d\n", 
           result5 == 0 ? "SUCCESS" : "FAILURE", -1000, result5);
    
    return (0);
}
