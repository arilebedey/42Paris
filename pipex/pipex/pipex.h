/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:50:12 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/14 07:26:45 by alebedev         ###   ########.fr       */
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
# define ERR_MALLOC "Malloc failed\n"

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	*pids;
	int		**pipes;
	int		infile;
	int		outfile;
	char	**paths;
	char	***cmds;
	int		cmd_count;
}			t_pipex;

// utils/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(const char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

// print_exit.c
int			print_warn(char *err);
int			print_error(char *err);
void		print_error_exit(t_pipex *ctx, char *err);
void		print_sys_error_exit(t_pipex *ctx, char *err);

// init_struct.c
void		init_struct(t_pipex *ctx, int cmd_count);

// free_pipex.c
void		free_pipex(t_pipex *ctx);

// connect.c
void		get_pipes(t_pipex *ctx);
void		get_file_fds(t_pipex *ctx, char **av, int ac);
void		get_paths(t_pipex *ctx, char **env);

// close.c
void		close_forks(t_pipex *ctx, int i);
void		close_pipes(t_pipex *ctx, int i);

// parse.c
char		**find_path(char **env);
char		**get_cmd(char **paths, char *cmd);

// pipeline.c
void		pipeline(t_pipex *ctx, char **av, char **env);

// children.c
void		setup_child_pipes(t_pipex *ctx, int cmd_index);
int			wait_for_children(t_pipex *ctx);

// exec_cmd.c
void		exec_cmd(t_pipex *ctx, char *cmd_str, char **env, int cmd_index);

#endif
