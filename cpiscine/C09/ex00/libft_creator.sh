cc ft_putchar.c -Werror -Wall -Wextra -c
cc ft_swap.c -Werror -Wall -Wextra -c
cc ft_putstr.c -Werror -Wall -Wextra -c
cc ft_strlen.c -Werror -Wall -Wextra -c
cc ft_strcmp.c -Werror -Wall -Wextra -c
ar crs libft.a ft_strcmp.o ft_strlen.o ft_putstr.o ft_swap.o ft_putchar.o
ranlib libft.a
