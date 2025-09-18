/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 07:55:10 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/17 08:45:45 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BSIZE
# define BSIZE 100
#endif

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

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
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
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

int	main(int ac, char **av)
{
	char	*needle;
	int		bytes;
	char	*buf;
	char	*stash;
	int		i;
	int		j;
	int		nlen;

	if (ac != 2)
		return (1);
	buf = malloc(BUFSIZ + 1);
	if (!buf)
	{
		perror("Error: ");
		return (1);
	}
	needle = av[1];
	stash = NULL;
	buf[BUFSIZ] = 0;
	while ((bytes = read(0, buf, BUFSIZ)) > 0)
	{
		buf[bytes] = 0;
		if (!stash)
		{
			stash = ft_strjoin(buf, NULL);
			if (!stash)
			{
				free(stash);
				free(buf);
				perror("Error: ");
				return (1);
			}
		}
		else
		{
			stash = ft_strjoin(stash, buf);
			if (!stash)
			{
				free(buf);
				perror("Error: ");
				return (1);
			}
		}
	}
	if (bytes == -1)
	{
		free(buf);
		free(stash);
		perror("Error: ");
		return (1);
	}
	free(buf);
	i = 0;
	nlen = 0;
	while (needle[nlen])
		nlen++;
	i = 0;
	while (stash && stash[i])
	{
		if (!ft_strncmp(&stash[i], needle, nlen))
		{
			for (j = 0; j < nlen; j++)
				write(1, "*", 1);
			i += nlen;
		}
		else
			write(1, &stash[i++], 1);
	}
	free(stash);
}
