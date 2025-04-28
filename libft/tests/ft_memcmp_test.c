/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:00 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/28 11:43:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

void run_test(const char *test_name, const void *s1, const void *s2, size_t n)
{
    int ft_result = ft_memcmp(s1, s2, n);
    int std_result = memcmp(s1, s2, n);
    int same_sign = (ft_result > 0 && std_result > 0) || 
                    (ft_result < 0 && std_result < 0) || 
                    (ft_result == 0 && std_result == 0);
    
    if (same_sign)
        printf("SUCCESS: %s\n", test_name);
    else
        printf("FAILURE: %s - Expected sign: %d, Got: %d\n", 
               test_name, std_result, ft_result);
}

int main(void)
{
    printf("ft_memcmp\n");
    
    // Test 1: Equal strings
    char *s1_t1 = "Hello";
    char *s2_t1 = "Hello";
    run_test("Test 1 - Equal strings - Input: \"Hello\" and \"Hello\" - length: 5", 
             s1_t1, s2_t1, 5);
    
    // Test 2: Different strings
    char *s1_t2 = "Hello";
    char *s2_t2 = "Hella";
    run_test("Test 2 - Different at last character - Input: \"Hello\" and \"Hella\" - length: 5", 
             s1_t2, s2_t2, 5);
    
    // Test 3: Different at first character
    char *s1_t3 = "Aello";
    char *s2_t3 = "Hello";
    run_test("Test 3 - Different at first character - Input: \"Aello\" and \"Hello\" - length: 5", 
             s1_t3, s2_t3, 5);
    
    // Test 4: Compare only first 3 characters of different strings
    char *s1_t4 = "Hello";
    char *s2_t4 = "Hella";
    run_test("Test 4 - Equal first 3 characters - Input: \"Hello\" and \"Hella\" - length: 3", 
             s1_t4, s2_t4, 3);
    
    // Test 5: Compare zero bytes
    char *s1_t5 = "Hello";
    char *s2_t5 = "Completely different";
    run_test("Test 5 - Zero bytes comparison - Input: \"Hello\" and \"Completely different\" - length: 0", 
             s1_t5, s2_t5, 0);
    
    // Test 6: Non-printable characters
    unsigned char s1_t6[] = {128, 129, 130, 0};
    unsigned char s2_t6[] = {128, 129, 131, 0};
    run_test("Test 6 - Non-printable characters - Input: binary data - length: 4", 
             s1_t6, s2_t6, 4);
    
    // Test 7: Compare same memory area
    char *s1_t7 = "Test";
    run_test("Test 7 - Same memory area - Input: \"Test\" and \"Test\" (same pointer) - length: 4", 
             s1_t7, s1_t7, 4);
    
    // Test 8: Null bytes in the middle
    char s1_t8[] = {'H', 'e', '\0', 'l', 'o'};
    char s2_t8[] = {'H', 'e', '\0', 'l', 'l'};
    run_test("Test 8 - Null bytes in the middle - Input: \"He\\0lo\" and \"He\\0ll\" - length: 5", 
             s1_t8, s2_t8, 5);
    
    // Test 9: Empty strings but non-zero length
    char *s1_t9 = "";
    char *s2_t9 = "";
    run_test("Test 9 - Empty strings - Input: \"\" and \"\" - length: 0", 
             s1_t9, s2_t9, 0);

    return 0;
}
