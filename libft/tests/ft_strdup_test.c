#include "../libft/libft.h"
#include <bsd/stdio.h>
#include <string.h>

void test_strdup(const char *test_name, const char *input)
{
	char *result_ft = ft_strdup(input);
	char *result_std = strdup(input);
	int is_equal = (strcmp(result_ft, result_std) == 0);
	
	printf("%s: Test %s - Input: \"%s\" - Result: %s\n", 
		is_equal ? "SUCCESS" : "FAILURE",
		test_name, 
		input,
		result_ft);
		
	free(result_ft);
	free(result_std);
}

int main(void)
{
	printf("ft_strdup\n");
	
	test_strdup("1 - Basic string", "Hello World");
	test_strdup("2 - Empty string", "");
	test_strdup("3 - Single character", "a");
	test_strdup("4 - String with special characters", "Hello!@#$%^&*()");
	test_strdup("5 - String with spaces", "   spaced   words   ");
	
	return (0);
}
