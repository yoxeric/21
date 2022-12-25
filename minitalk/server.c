/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:40:16 by yhachami          #+#    #+#             */
/*   Updated: 2022/12/23 23:25:47 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

#include<signal.h>
#include<unistd.h>

void	print_msg(int *msg)
{
	int	i;

	i = 0;
	printf("message : ");
	while (i < 8)
		printf("%d", msg[i++]);
	printf("\n");
	return ;
}

int	power(int x, int n)
{
	int	result;

	result = 1;
	while (n--)
		result *= x;
	return (result);
}

char	decode(int *msg)
{
	int	x;
	int	i;
	int	n;

	i = 0;
	n = 7;
	x = 0;
	while (i < 8)
	{
		x += (msg[i] * power(2, n));
		i++;
		n--;
	}
	return ((char) x);
}

void	handler(int sig)
{
	static int	i;
	int			message[8];
	char		c;

	if (sig == 30)
		message[i++] = 0;
	if (sig == 31)
		message[i++] = 1;
	if (i == 8)
	{
		//printf("server : received a response %d \n", sig);
		//print_msg(message);
		c = decode(message);
		write(1, &c, 1);
		i = 0;
	}
}

int	main()
{
	pid_t	pid;

	pid = getpid();
	printf("server : PID is %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("server : wating for client\n");
	while (1)
		sleep(1);
	return (0);
}
