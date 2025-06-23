/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:50:12 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/23 17:09:51 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_INFILE "Infile\n"
# define ERR_OUTFILE "Outfile\n"
# define ERR_PIPE "Pipe\n"
# define ERR_CMD "Command not found\n"
# define ERR_PATH "Path not found\n"
# define ERR_EXECVE "Failed to execute command\n"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infile;
	int		outfile;
	char	**paths;
	char	**cmd;
}			t_pipex;

// utils/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(const char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

// error.c
int			print_warn(char *err);
int			print_error(char *err);
void		perror_exit(char *err);

// parse.c
char		**find_path(char **env);
char		**get_cmd(char **paths, char *cmd);

// free.c
void		close_pipes(t_pipex *ctx);
void		free_child(t_pipex *ctx);
int			free_parent(t_pipex *ctx);
void		free_paths(char **paths);

// processes.c
void		first_child(t_pipex ctx, char *av[], char *env[]);
void		second_child(t_pipex ctx, char *av[], char *env[]);

#endif
