#include "ft_printf.h"

int	main(void)
{
	int				count;
	char			*str = "Hello, world!";
	int				num = -42;
	unsigned int	u_num = 123456789;
	void			*ptr = str;

	ft_printf("===== Testing ft_printf =====\n");

	count = ft_printf("Char: %c\n", 'A');
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("String: %s\n", str);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Decimal: %d | Integer: %i\n", num, 123);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Unsigned: %u\n", u_num);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Hex lowercase: %x\n", 3735928559u);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Hex UPPERCASE: %X\n", 3735928559u);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Pointer: %p\n", ptr);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Null string: %s\n", (char *)NULL);
	ft_printf("Printed %d characters.\n\n", count);

	count = ft_printf("Percent sign: %%\n");
	ft_printf("Printed %d characters.\n\n", count);

	return (0);
}
