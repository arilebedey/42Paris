/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits_mine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:50:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/22 22:27:30 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"

*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				shift;
	unsigned char	bit;

	shift = 8;
	while (shift--)
	{
		bit = (octet >> shift) & 1;
		bit += '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	unsigned char	value;

	value = 2;
	print_bits(value);
	return (0);
}
