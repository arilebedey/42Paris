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
	int		pid;
	char	*arg_nulled;
	int		p[2];

	(void)ac;
	i = 1;
	in_fd = 0;
	while (av[i])
	{
		start = i;
		is_piped = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (i == start)
		{
			i++;
			continue ;
		}
		if (!strcmp(av[start], "cd"))
		{
			if (i - start != 2)
				ft_putstr("error: cd wrong args\n", 2);
			else if (chdir(av[start + 1]) == -1)
				ft_putstr("error: cd cannot cd to dir\n", 2);
			continue ;
		}
		if (av[i] && !strcmp(av[i], "|"))
			is_piped = 1;
		arg_nulled = av[i];
		av[i] = NULL;
		if (is_piped && pipe(p) == -1)
			fatal_err();
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
				if (dup2(in_fd, 0) < 0)
				{
					if (is_piped)
					{
						close(p[0]);
						close(p[1]);
					}
					fatal_err();
				}
			}
			if (is_piped)
			{
				if (dup2(p[1], 1) < 0)
				{
					if (in_fd)
						close(in_fd);
					fatal_err();
				}
			}
			execve(av[start], &av[start], env);
			fatal_err();
		}
		else
		{
			if (in_fd)
				close(in_fd);
			if (is_piped)
			{
				in_fd = p[0];
				close(p[1]);
			}
			else
				in_fd = 0;
			av[i] = arg_nulled;
			waitpid(pid, 0, 0);
		}
		if (av[i])
			i++;
	}
	return (0);
}
