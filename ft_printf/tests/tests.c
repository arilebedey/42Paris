/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:10:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/30 14:31:13 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int number = 42;
    char *string = "Hello, world!";
    void *ptr = &number;
    char c = 'Z';
    
    // Basic tests with manual comparison
    printf("\n==== BASIC COMPARISON TESTS ====\n");
    
    printf("\nTesting %%c:\n");
    printf("Standard printf: ");
    int std_ret = printf("Character: %c\n", c);
    printf("Your ft_printf: ");
    int ft_ret = ft_printf("Character: %c\n", c);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%s:\n");
    printf("Standard printf: ");
    std_ret = printf("String: %s\n", string);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("String: %s\n", string);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%d and %%i:\n");
    printf("Standard printf: ");
    std_ret = printf("Integer: %d or %i\n", number, number);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Integer: %d or %i\n", number, number);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%u:\n");
    printf("Standard printf: ");
    std_ret = printf("Unsigned: %u\n", UINT_MAX);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Unsigned: %u\n", UINT_MAX);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%x and %%X:\n");
    printf("Standard printf: ");
    std_ret = printf("Hexadecimal: %x or %X\n", 0xABCDEF, 0xABCDEF);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Hexadecimal: %x or %X\n", 0xABCDEF, 0xABCDEF);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%p:\n");
    printf("Standard printf: ");
    std_ret = printf("Pointer: %p\n", ptr);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Pointer: %p\n", ptr);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting NULL pointer with %%p:\n");
    printf("Standard printf: ");
    std_ret = printf("NULL Pointer: %p\n", NULL);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("NULL Pointer: %p\n", NULL);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting %%%%:\n");
    printf("Standard printf: ");
    std_ret = printf("Percent sign: %%\n");
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Percent sign: %%\n");
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\n==== EDGE CASE TESTS ====\n");
    
    printf("\nTesting INT_MIN with %%d:\n");
    printf("Standard printf: ");
    std_ret = printf("INT_MIN: %d\n", INT_MIN);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("INT_MIN: %d\n", INT_MIN);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    printf("\nTesting INT_MAX with %%d:\n");
    printf("Standard printf: ");
    std_ret = printf("INT_MAX: %d\n", INT_MAX);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("INT_MAX: %d\n", INT_MAX);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    // Be careful with NULL and %s - compiler may warn
    printf("\nTesting NULL string handling (your ft_printf only):\n");
    printf("Your ft_printf: ");
    ft_ret = ft_printf("NULL string: %s\n", NULL);
    printf("Return value: %d (expected behavior is to print \"(null)\")\n", ft_ret);
    
    printf("\nTesting multiple mixed formats:\n");
    printf("Standard printf: ");
    std_ret = printf("Mixed: %c %s %d %i %u %x %X %p %%\n", 
                    'A', "test", 42, -42, 123456, 0xabcdef, 0xABCDEF, ptr);
    printf("Your ft_printf: ");
    ft_ret = ft_printf("Mixed: %c %s %d %i %u %x %X %p %%\n", 
                      'A', "test", 42, -42, 123456, 0xabcdef, 0xABCDEF, ptr);
    printf("Return values - printf: %d, ft_printf: %d %s\n", 
           std_ret, ft_ret, (std_ret == ft_ret) ? "✓" : "✗");
    
    return (0);
}
