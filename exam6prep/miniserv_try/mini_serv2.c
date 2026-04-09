#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int max_fd = 0;
int count = 0;

int ids[65536];
char *msgs[65536];

char bufr[42], bufw[42];

fd_set afds, rfds, wfds;

int sockfd;

void fatal_error(char *str)
{
	if (!str[0])
		str = "Fatal error\n";
	write(2, str, strlen(str));
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &afds))
			close(fd);
	}
	exit(1);
}

int create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (max_fd < 0)
		fatal_error("");
	FD_SET(max_fd, &afds);
	return max_fd;
}

void notify_others(int aut, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && aut != fd && fd != sockfd) 
			send(fd, str, strlen(str), 0);
	}
}

void register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(bufw, "server: client %d just arrived\n", ids[fd]);
	notify_others(fd, bufw);
}

void remove_client(int fd)
{
	free(msgs[fd]);
	msgs[fd] = NULL;
	FD_CLR(fd, &afds);
	close(fd);
	sprintf(bufw, "server: client %d just left\n", ids[fd]);
	ids[fd] = 0;
	notify_others(fd, bufw);
}

void send_msg(int fd)
{
	char *msg;
	int code;

	while ((code = extract_message(&(msgs[fd]), &msg)) == 1)
	{
		sprintf(bufw, "client %d: ", ids[fd]);
		notify_others(fd, bufw);
		notify_others(fd, msg);
		free(msg);
	}
	if (code == -1)
		fatal_error("");
}

int main(int ac, char **av)
{
	if (ac != 2)
		fatal_error("Wrong number of arguments\n");

	FD_ZERO(&afds);
	sockfd = create_socket();

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal_error("");
	if (listen(sockfd, SOMAXCONN) != 0)
		fatal_error("");

	while (1)
	{
		wfds = rfds = afds;

		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			fatal_error("");

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
					continue;

			if (fd == sockfd)
			{
				socklen_t addrlen = sizeof(servaddr);
				int cfd = accept(sockfd, (struct sockaddr *)&servaddr, &addrlen);
				if (cfd >= 0)
				{
					register_client(cfd);
					break;
				} 
			}
			else
			{
				int bytes = recv(fd, bufr, sizeof(bufr) - 1, 0);
				if (bytes <= 0)
				{
					remove_client(fd);
					break;
				}
				bufr[bytes] = 0;
				msgs[fd] = str_join(msgs[fd], bufr);
				if (!msgs[fd])
					fatal_error("");
				send_msg(fd);
			}
		}
	}
	return 0;
}

