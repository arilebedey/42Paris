#include "get_next_line.h"

int	main(void)
{
	char	*line;

	line = get_next_line(0);
	if (line)
		printf("line:%s\n", line);
	free(line);
	line = get_next_line(0);
	if (line)
		printf("line:%s\n", line);
	free(line);
	line = get_next_line(0);
	if (line)
		printf("line:%s\n", line);
	free(line);
	line = get_next_line(0);
	if (line)
		printf("line:%s\n", line);
	free(line);
}
