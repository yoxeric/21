/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:39:05 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/23 23:38:55 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int	*encode(char c)
{
	int	*msg;
	int	x;
	int	i;

	msg = (int *) malloc(8 * sizeof(int));
	if (!msg)
		return (0);
	x = c;
	i = 7;
	while (i > 0)
	{
		msg[i--] = x % 2;
		x /= 2;
	}
	return (msg);
}

void	send(pid_t server_pid, int *message)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message[i] == 0)
			if (kill(server_pid, SIGUSR1) == -1)
				exit(0);
		else if (message[i] == 1)
			if (kill(server_pid, SIGUSR2) == -1)
				exit(0);
		i++;
		usleep(50);
	}
	free(message);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		*message;
	int		i;

	server_pid = atoi(argv[1]);
	if (argc != 3)
	{
		printf("whats happening");
		exit(0);
	}
	printf("client : sending signal %d\n", argv[2][0]);
	i = 0;
	while (argv[2][i])
	{
		message = encode(argv[2][i]);
		send(server_pid, message);
		i++;
	}
	return (0);
}
