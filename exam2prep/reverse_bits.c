/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_mine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:16:53 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/22 22:27:24 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				shift;
	unsigned char	bit;

	shift = 8;
	bit = 0;
	while (shift--)
	{
		bit <<= 1;
		bit |= (octet >> shift) & 1;
	}
	return (bit);
}

int	main(void)
{
	unsigned char	reversed;
	unsigned char	octet;

	octet = 0b01010101;
	reversed = reverse_bits(octet);
	printf("Original: 0b01010101 (decimal: %d)\n", octet);
	printf("Reversed: 0b10101010 (decimal: %d)\n", reversed);
	return (0);
}
