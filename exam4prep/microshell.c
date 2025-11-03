#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	fatal_err(void)
{
	ft_putstr("fatal\n", 2);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		start;
	int		in_fd;
	int		is_piped;
	pid_t	pid;
	char	*arg_nulled;
	int		p[2];

	(void)ac;
	i = 1;
	in_fd = 0;
	while (av[i])
	{
		start = i;
		is_piped = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (start == i)
		{
			i++;
			continue ;
		}
		if (!strcmp(av[start], "cd"))
		{
			if (i - start != 2)
				ft_putstr("cd: wrong args", 2);
			else if (chdir(av[start + 1]) == -1)
			{
				ft_putstr("cd: cannot cd to ", 2);
				ft_putstr(av[start + 1], 2);
				ft_putstr("\n", 2);
			}
			continue ;
		}
		if (av[i] && !strcmp(av[i], "|"))
			is_piped = 1;
		arg_nulled = av[i];
		av[i] = NULL;
		if (is_piped && pipe(p) == -1)
		{
			if (in_fd)
				close(in_fd);
			fatal_err();
		}
		pid = fork();
		if (pid == -1)
		{
			if (in_fd)
				close(in_fd);
			if (is_piped)
			{
				close(p[0]);
				close(p[1]);
			}
			fatal_err();
		}
		if (pid == 0)
		{
			if (in_fd)
			{
				if (dup2(in_fd, 0) == -1)
				{
					close(in_fd);
					if (is_piped)
					{
						close(p[0]);
						close(p[1]);
					}
					fatal_err();
				}
				close(in_fd);
			}
			if (is_piped)
			{
				if (dup2(p[1], 1) == -1)
				{
					close(p[1]);
					close(p[0]);
					if (in_fd)
						close(in_fd);
					fatal_err();
				}
				close(p[1]);
				close(p[0]);
			}
			execve(av[start], &av[start], env);
			ft_putstr("exec: couldn't exec ", 2);
			ft_putstr(av[start], 2);
			ft_putstr("\n", 2);
			// NOTE: Don't forget to exit(1) if execve fails
			exit(1);
		}
		else
		{
			if (in_fd)
			{
				close(in_fd);
			}
			if (is_piped)
			{
				close(p[1]);
				in_fd = p[0];
			}
			// NOTE: if not piping, reset the in_fd to 0!
			else
				in_fd = 0;
			waitpid(pid, NULL, 0);
			av[i] = arg_nulled;
		}
		if (av[i])
			i++;
	}
	if (in_fd)
		close(in_fd);
	return (0);
}
