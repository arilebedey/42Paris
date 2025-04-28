#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("ft_isalnum\n");
    
    /* Test 1 - Character just below 'a' in ASCII ('`' = 96) */
    int result1 = ft_isalnum('a' - 1);
    printf("%s: Test 1 - Character just below 'a' - Input: \"%c\" - Result: %d\n", 
           result1 == 0 ? "SUCCESS" : "FAILURE", 'a' - 1, result1);
    
    /* Test 2 - Character just above 'z' in ASCII ('{' = 123) */
    int result2 = ft_isalnum('z' + 1);
    printf("%s: Test 2 - Character just above 'z' - Input: \"%c\" - Result: %d\n", 
           result2 == 0 ? "SUCCESS" : "FAILURE", 'z' + 1, result2);
    
    /* Test 3 - Character just below '0' in ASCII ('/' = 47) */
    int result3 = ft_isalnum('0' - 1);
    printf("%s: Test 3 - Character just below '0' - Input: \"%c\" - Result: %d\n", 
           result3 == 0 ? "SUCCESS" : "FAILURE", '0' - 1, result3);
    
    /* Test 4 - Character just above '9' in ASCII (':' = 58) */
    int result4 = ft_isalnum('9' + 1);
    printf("%s: Test 4 - Character just above '9' - Input: \"%c\" - Result: %d\n", 
           result4 == 0 ? "SUCCESS" : "FAILURE", '9' + 1, result4);
    
    /* Test 5 - Character '9' - Should check if it's considered alphanumeric */
    int result5 = ft_isalnum('9');
    printf("%s: Test 5 - Character '9' - Input: \"%c\" - Result: %d\n", 
           result5 == 1 ? "SUCCESS" : "FAILURE", '9', result5);
    
    return (0);
}
