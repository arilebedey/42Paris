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
	int		is_piped;
	int		p[2];
	char	*arg_null;
	int		pid;
	int		in_fd;

	(void)ac;
	i = 1;
	in_fd = 0;
	while (av[i])
	{
		start = i;
		is_piped = 0;
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		if (start == i)
		{
			i++;
			continue ;
		}
		if (strcmp(av[start], "cd") == 0)
		{
			if (i - start != 2)
				ft_putstr("error: cd: bad arguments\n", 2);
			else if (chdir(av[start + 1]) != 0)
			{
				ft_putstr("error: cd: cannot change diretory to ", 2);
				ft_putstr(av[start + 1], 2);
				ft_putstr("\n", 2);
			}
			continue ;
		}
		if (av[i] && strcmp(av[i], "|") == 0)
			is_piped = 1;
		if (is_piped && pipe(p) != 0)
			fatal_err();
		arg_null = av[i];
		av[i] = NULL;
		pid = fork();
		if (pid == -1)
		{
			if (in_fd)
				close(in_fd);
			if (is_piped)
			{
				close(p[1]);
				close(p[0]);
			}
			fatal_err();
		}
		if (pid == 0)
		{
			if (in_fd)
			{
				if (dup2(in_fd, 0) < 0)
					fatal_err();
				close(in_fd);
			}
			if (is_piped)
			{
				close(p[0]);
				if (dup2(p[1], 1) < 0)
					fatal_err();
				close(p[1]);
			}
			execve(av[start], &av[start], env);
			ft_putstr("error: cannot exec ", 2);
			ft_putstr(av[start], 2);
			ft_putstr("\n", 2);
			exit(1);
		}
		else
		{
			if (in_fd)
				close(in_fd);
			if (is_piped)
			{
				close(p[1]);
				in_fd = p[0];
			}
			else
				in_fd = 0;
			av[i] = arg_null;
			waitpid(pid, NULL, 0);
		}
		if (av[i])
			i++;
	}
	return (0);
}
