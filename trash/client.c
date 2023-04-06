/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:39:05 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/25 20:12:05 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void	print_message(int *msg, char c)
{
	int	i;
	
	i = 0;
	printf(" %c   | %d | ", c, c);
	while (i < 8)
		printf("%d", msg[i++]);
	printf("\n");
	return ;
}

int	*encode(unsigned char c)
{
	int	*msg;
	int	x;
	int	i;

	msg = (int *) malloc(8 * sizeof(int));
	x = c;
	i = 7;
	while (i > 0)
	{
		msg[i--] = x % 2;
		x /= 2;
	}
	return (msg);
}

void	send(pid_t server_pid, int *msg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (msg[i] == 0)
			kill(server_pid, SIGUSR1);
		else if (msg[i] == 1)
			kill(server_pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		*message;
	int		i;

	server_pid = atoi(argv[1]);
	if (argc == 3)
	{
		printf("client : sending signal\n");
		printf("char | int | binaire\n");
		i = 0;
		while (argv[2][i])
		{	
			message = encode(argv[2][i]);
			print_message(message , argv[2][i]);
			send(server_pid, message);
			i++;
		}
	}
	else
	{
		printf("whats happening");
		exit(0);
	}
	return (0);
}
