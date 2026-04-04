/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:42:15 by alebedev          #+#    #+#             */
/*   Updated: 2026/04/04 10:28:53 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

static char	*read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	size_t	stash_len;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !init_stash(&stash, buffer))
		return (NULL);
	stash_len = ft_strlen(stash);
	if (ft_strchr(stash, '\n'))
		return (free(buffer), stash);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer, stash_len);
		if (!stash)
			return (free(buffer), NULL);
		stash_len += bytes_read;
		if (ft_strchr(stash + stash_len - bytes_read, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char	*stashes[FD_SETSIZE] = {NULL};
	char		*line;

	if (fd < 0 || fd >= FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	stashes[fd] = read_file(fd, stashes[fd]);
	if (!stashes[fd])
	{
		stashes[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stashes[fd]);
	stashes[fd] = update_stash(stashes[fd]);
	return (line);
}
