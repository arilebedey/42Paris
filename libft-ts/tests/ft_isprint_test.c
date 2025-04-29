/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tester <tester@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/04/28 10:54:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>

void	test_isprint(int c, int test_num, const char *description)
{
	int		ft_result;
	int		expected;
	char	*status;

	ft_result = ft_isprint(c);
	expected = isprint(c);
	
	// Convert to 1/0 boolean result for consistent comparison
	if (ft_result != 0)
		ft_result = 1;
	if (expected != 0)
		expected = 1;
	
	if (ft_result == expected)
		status = "SUCCESS";
	else
		status = "FAILURE";
		
	printf("%s: Test %d - %s - Input: %d (%c) - Result: %d\n", 
		status, test_num, description, c, 
		(c >= 32 && c <= 126) ? c : ' ', ft_result);
}

int	main(void)
{
	printf("ft_isprint\n");
	test_isprint('A', 1, "Standard printable character (uppercase letter)");
	test_isprint('z', 2, "Standard printable character (lowercase letter)");
	test_isprint('0', 3, "Standard printable character (digit)");
	test_isprint(' ', 4, "Space character (ASCII 32)");
	test_isprint('~', 5, "Tilde character (ASCII 126)");
	test_isprint(31, 6, "Non-printable character (ASCII 31)");
	test_isprint(127, 7, "Delete character (ASCII 127)");
	test_isprint(0, 8, "Null character (ASCII 0)");
	test_isprint(200, 9, "Extended ASCII character");
	
	return (0);
}
