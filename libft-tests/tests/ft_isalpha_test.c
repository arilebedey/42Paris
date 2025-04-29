#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("ft_isalpha\n");
    
    /* Test 1 - Character just below 'A' in ASCII ('@' = 64) */
    int result1 = ft_isalpha('A' - 1);
    printf("%s: Test 1 - Character just below 'A' - Input: \"%c\" - Result: %d\n", 
           result1 == 0 ? "SUCCESS" : "FAILURE", 'A' - 1, result1);
    
    /* Test 2 - Character just above 'Z' in ASCII ('[' = 91) */
    int result2 = ft_isalpha('Z' + 1);
    printf("%s: Test 2 - Character just above 'Z' - Input: \"%c\" - Result: %d\n", 
           result2 == 0 ? "SUCCESS" : "FAILURE", 'Z' + 1, result2);
    
    /* Test 3 - Character just below 'a' in ASCII ('`' = 96) */
    int result3 = ft_isalpha('a' - 1);
    printf("%s: Test 3 - Character just below 'a' - Input: \"%c\" - Result: %d\n", 
           result3 == 0 ? "SUCCESS" : "FAILURE", 'a' - 1, result3);
    
    /* Test 4 - Character just above 'z' in ASCII ('{' = 123) */
    int result4 = ft_isalpha('z' + 1);
    printf("%s: Test 4 - Character just above 'z' - Input: \"%c\" - Result: %d\n", 
           result4 == 0 ? "SUCCESS" : "FAILURE", 'z' + 1, result4);
    
    /* Test 5 - Valid lowercase letter */
    int result5 = ft_isalpha('m');
    printf("%s: Test 5 - Valid lowercase letter - Input: \"%c\" - Result: %d\n", 
           result5 == 1 ? "SUCCESS" : "FAILURE", 'm', result5);
    
    return (0);
}
