#include <stdio.h>
#include <bsd/string.h>
#include "../libft/libft.h"

#define SUCCESS "SUCCESS"
#define FAILURE "FAILURE"

void test_strlcpy(char *description, char *src, size_t dstsize, size_t expected_ret)
{
	char dst1[100] = {0};
	char dst2[100] = {0};
	size_t ret1, ret2;
	int result = 1;

	ret1 = ft_strlcpy(dst1, src, dstsize);
	ret2 = strlcpy(dst2, src, dstsize);

	if (ret1 != ret2)
		result = 0;
	if (strcmp(dst1, dst2) != 0)
		result = 0;
	if (ret1 != expected_ret)
		result = 0;

	printf("%s: Test - %s - Input: \"%s\", dstsize: %zu - Result: %zu\n", 
		result ? SUCCESS : FAILURE, description, src, dstsize, ret1);
}

int main(void)
{
	printf("ft_strlcpy\n");

	// Test 1: Basic copy with enough space
	test_strlcpy("Basic copy with enough space", "Hello", 10, 5);

	// Test 2: Copy with exact size (including null terminator)
	test_strlcpy("Copy with exact size", "Hello", 6, 5);

	// Test 3: Copy with limited size
	test_strlcpy("Copy with limited size", "Hello", 3, 5);

	// Test 4: Copy with dstsize = 0
	test_strlcpy("Copy with dstsize = 0", "Hello", 0, 5);

	return 0;
}
