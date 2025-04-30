#include "libftprintf.h"

static	int	ft_print_hex_address(unsigned long long n)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		count += ft_print_hex_address(n / 16);
	count += ft_print_char(hex_digits[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int					count;
	unsigned long long	address;

	count = 0;
	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	address = (unsigned long long)ptr;
	count += ft_print_str("0x");
	count += ft_print_hex_address(address);
	return (count);
}
