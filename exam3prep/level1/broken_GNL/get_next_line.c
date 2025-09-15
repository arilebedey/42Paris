#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char const *s1, int n)
{
	char	*new;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(char const *s1)
{
	char	*new;
	int		i;

	if (!s1)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

int	fill_stash(int fd, char **stash)
{
	char	*b;
	char	*line;
	char	*tmp;
	int		bytes;

	bytes = 0;
	line = NULL;
	b = malloc(BUFFER_SIZE + 1);
	if (!b)
		return (1);
	bytes = 1;
	while (bytes > 0 && (!ft_strchr(*stash, '\n')))
	{
		bytes = read(fd, b, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(b);
			return (1);
		}
		b[bytes] = '\0';
		if (!*stash)
			*stash = ft_strdup(b);
		else
		{
			tmp = ft_strjoin(*stash, b);
			free(*stash);
			*stash = tmp;
		}
	}
	free(b);
	return (0);
}

char	*extract_line(char **stash)
{
	char	*line;
	int		i;
	char	*str;
	char	*new_stash;

	str = *stash;
	if (!str || !*str)
		return (NULL);
	line = NULL;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_strndup(str, i);
	new_stash = ft_strdup(str + i);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024)
		return (NULL);
	if (fill_stash(fd, &stash))
		return (NULL);
	line = extract_line(&stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
