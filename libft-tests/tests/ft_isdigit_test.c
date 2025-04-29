#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
    printf("ft_isdigit\n");
    
    /* Test 1 - Character just below '0' in ASCII ('/' = 47) */
    int result1 = ft_isdigit('0' - 1);
    printf("%s: Test 1 - Character just below '0' - Input: \"%c\" - Result: %d\n", 
           result1 == 0 ? "SUCCESS" : "FAILURE", '0' - 1, result1);
    
    /* Test 2 - Character just above '9' in ASCII (':' = 58) */
    int result2 = ft_isdigit('9' + 1);
    printf("%s: Test 2 - Character just above '9' - Input: \"%c\" - Result: %d\n", 
           result2 == 0 ? "SUCCESS" : "FAILURE", '9' + 1, result2);
    
    /* Test 3 - Lowest valid digit '0' */
    int result3 = ft_isdigit('0');
    printf("%s: Test 3 - Lowest valid digit - Input: \"%c\" - Result: %d\n", 
           result3 == 1 ? "SUCCESS" : "FAILURE", '0', result3);
    
    /* Test 4 - Highest valid digit '9' */
    int result4 = ft_isdigit('9');
    printf("%s: Test 4 - Highest valid digit - Input: \"%c\" - Result: %d\n", 
           result4 == 1 ? "SUCCESS" : "FAILURE", '9', result4);
    
    /* Test 5 - Letter character */
    int result5 = ft_isdigit('A');
    printf("%s: Test 5 - Letter character - Input: \"%c\" - Result: %d\n", 
           result5 == 0 ? "SUCCESS" : "FAILURE", 'A', result5);
    
    return (0);
}
