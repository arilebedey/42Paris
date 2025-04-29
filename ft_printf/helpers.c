#include "libftprintf.h"

int count_bytes_in_string(char *string)
{
	size_t	byte_count;
	unsigned char	*n_string;

	n_string = (unsigned char *) string;
	byte_count = 0;
	while (n_string[byte_count])
		byte_count++;
	return (byte_count);
}
