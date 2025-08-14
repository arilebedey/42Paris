/* Write a function that reads from stdin and find the string
 * present in the argument and replace it with '*' and print it.
 *
 * Use perror prefixed by "Error: " to show the malloc/read errors
 * and return 1.
 *
 * During evaluation a custom read implementation will be imported
 * and different buffer sizes will be set.
 *
 * Example:
 * $>echo "abcabcdabdab" | ./a.out "abc" | cat -A
 * $>******dabdab$
 * $>
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		perror("Error: ");
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		perror("Error: ");
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	char	*stash;
	char	buffer[2];
	char	*tmp;
	ssize_t	bytes;

	stash = NULL;
	(void)av;
	if (ac != 2)
		return (1);
	buffer[1] = '\0';
	while ((bytes = read(0, buffer, 1)) > 0)
	{
		if (!stash)
			stash = strdup(buffer);
		tmp = buffer;
		if (read(0, buffer, 1) < 0)
			return (perror("Error: "), 1);
		if (buffer[0])
		{
			stash = ft_strjoin(tmp, buffer);
			if (!stash)
				return (perror("Error: "), 1);
		}
	}
	printf("%s", stash);
}
