/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tester <tester@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:45:00 by tester            #+#    #+#             */
/*   Updated: 2025/05/02 12:07:22 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(const char *str, char c);

static void	free_split_result(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	test_split(const char *str, char c, char **expected, int expected_size)
{
	char	**result;
	int		i;
	int		success;

	result = ft_split(str, c);
	success = 1;
	
	if (!result && expected)
		return (0);
	if (result && !expected)
	{
		free_split_result(result);
		return (0);
	}
	
	i = 0;
	while (i < expected_size)
	{
		if (!result[i] || strcmp(result[i], expected[i]) != 0)
		{
			success = 0;
			break;
		}
		i++;
	}
	
	if (success && result[expected_size] != NULL)
		success = 0;
		
	free_split_result(result);
	return (success);
}

int	main(void)
{
	int		success;
	char	*expected1[] = {"Hello", "World"};
	char	*expected2[] = {"apple", "banana", "cherry"};
	char	*expected3[] = {"42", "is", "fun"};
	char	*expected4[] = {"one"};
	char	*expected5[] = {"a", "b", "c", "d", "e"};
	char	*expected6[] = {""};

	printf("ft_split\n");
	
	success = test_split("Hello,World", ',', expected1, 2);
	printf("%s: Test 1 - Basic split with comma - Input: \"Hello,World\", ',' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"Hello\", \"World\"}" : "Incorrect");
	
	success = test_split("apple-banana-cherry", '-', expected2, 3);
	printf("%s: Test 2 - Multiple splits with hyphen - Input: \"apple-banana-cherry\", '-' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"apple\", \"banana\", \"cherry\"}" : "Incorrect");
	
	success = test_split("42 is fun", ' ', expected3, 3);
	printf("%s: Test 3 - Split with spaces - Input: \"42 is fun\", ' ' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"42\", \"is\", \"fun\"}" : "Incorrect");
	
	success = test_split("one", 'x', expected4, 1);
	printf("%s: Test 4 - No delimiter in string - Input: \"one\", 'x' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"one\"}" : "Incorrect");
	
	success = test_split("a:b:c:d:e", ':', expected5, 5);
	printf("%s: Test 5 - Multiple single characters - Input: \"a:b:c:d:e\", ':' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"a\", \"b\", \"c\", \"d\", \"e\"}" : "Incorrect");
	
	success = test_split("", ',', expected6, 0);
	printf("%s: Test 6 - Empty string - Input: \"\", ',' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{}" : "Incorrect");
	
	success = test_split(",,,,", ',', expected6, 0);
	printf("%s: Test 7 - String with only delimiters - Input: \",,,,\", ',' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{}" : "Incorrect");
	
	success = test_split("Hello,,,World", ',', expected1, 2);
	printf("%s: Test 8 - Multiple consecutive delimiters - Input: \"Hello,,,World\", ',' - Result: %s\n", 
		success ? "SUCCESS" : "FAILURE", success ? "{\"Hello\", \"World\"}" : "Incorrect");
	
	return (0);
}
