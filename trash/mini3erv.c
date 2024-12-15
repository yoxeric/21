#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int sockfd, connfd, max;
socklen_t len;
struct sockaddr_in servaddr, cli;

fd_set all, rfd, wfd;
char *msgs[200000], rbuf[1024], wbuf[69];
char ids[200000], id = 0;

void fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

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
				fatal();
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
		fatal();
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void radio(int sndr, char *msg)
{
	for (int fd = 0; fd <= max; ++fd)
	{
		if (FD_ISSET(fd, &wfd) && fd != sndr)
			send(fd, msg, strlen(msg), 0);
	}
}

void snd(int clnt)
{
	char *msg = 0;
	while (extract_message(&(msgs[clnt]), &msg))
	{
		sprintf(wbuf, "client %d: ", ids[clnt]);
		radio(clnt, wbuf);
		radio(clnt, msg);
		free(msg);
	}
}

void jn(int clnt)
{
	if (max < clnt)
		max = clnt;
	msgs[clnt] = 0;
	ids[clnt] = id++;
	sprintf(wbuf, "server: client %d just arrived\n", ids[clnt]);
	radio(clnt, wbuf);
	FD_SET(clnt, &all);
}

void lv(int clnt)
{
	free(msgs[clnt]);
	sprintf(wbuf, "server: client %d just left\n", ids[clnt]);
	radio(clnt, wbuf);
	FD_CLR(clnt, &all);
	close(clnt);
}

int main(int ac, char** av) {
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		fatal();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();
	if (listen(sockfd, 10) != 0)
		fatal();

	FD_ZERO(&all);
	FD_SET(sockfd, &all);
	max = sockfd;
	while (1)
	{
		rfd = all;
		wfd = all;
		if (select(max + 1, &rfd, &wfd, 0, 0) < 0)
			fatal();
		for (int fd = 0; fd <= max; ++fd)
		{
			if (FD_ISSET(fd, &rfd))
			{
				if (fd == sockfd)
				{
					len = sizeof(cli);
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd >= 0) 
					{
						jn(connfd);
						break ;
				    } 
				}
				else
				{
					int sss = recv(fd, rbuf, 1023, 0);
					if (sss <= 0)
					{
						lv(fd);
						break;
					}
					rbuf[sss] = 0;
					msgs[fd] = str_join(msgs[fd], rbuf);
					snd(fd);
				}
			}
		}
	}
}