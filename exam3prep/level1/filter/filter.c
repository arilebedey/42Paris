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

#ifndef BSIZE
# define BSIZE 100
#endif

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
	{
		perror("Error: ");
		return (NULL);
	}
	str[i] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s2)
		return (ft_strdup(s1));
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
	{
		perror("Error: ");
		return (NULL);
	}
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
	str[i] = '\0';
	free(s1);
	return (str);
}

void	replace_with_stars(char *text, char *pattern)
{
	int	pat_len;
	int	j;

	pat_len = 0;
	while (pattern[pat_len])
		pat_len++;
	for (int i = 0; text[i]; i++)
	{
		j = 0;
		while (pattern[j] && text[i + j] == pattern[j])
			j++;
		if (j == pat_len)
		{
			for (int k = 0; k < pat_len; k++)
				text[i + k] = '*';
			i += pat_len - 1;
		}
	}
}

int	main(int ac, char **av)
{
	char	*stash;
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	stash = NULL;
	(void)av;
	if (ac != 2)
		return (1);
	buffer = malloc(sizeof(char) * (BSIZE + 1));
	if (!buffer)
	{
		perror("Error: ");
		return (1);
	}
	buffer[BSIZE] = '\0';
	while ((bytes = read(0, buffer, BSIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (!stash)
			stash = ft_strjoin(buffer, NULL);
		else
		{
			tmp = ft_strjoin(stash, buffer);
			if (!tmp)
				return (1);
			stash = tmp;
		}
	}
	free(buffer);
	if (stash)
	{
		replace_with_stars(stash, av[1]);
		printf("%s", stash);
		free(stash);
	}
	return (0);
}
