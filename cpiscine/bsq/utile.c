#include "bsq.h"

int	count_lines(char *str)
{
	int	i;
	int	nl_count;

	i = -1;
	nl_count = 0;
	while (str[++i])
		if (str[i] == '\n')
			nl_count++;
	return (nl_count);
}

int	is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}
