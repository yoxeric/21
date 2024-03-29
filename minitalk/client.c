/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:56:28 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/20 00:12:00 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*encode(int c)
{
	int	i;
	int	*binary;

	binary = (int *) malloc(8 * sizeof(int));
	i = 7;
	while (i >= 0)
	{
		binary[i--] = c % 2;
		c /= 2;
	}
	return (binary);
}

void	send_character(pid_t server_pid, unsigned char c)
{
	int	*binary;
	int	i;

	binary = encode(c);
	i = 0;
	while (i < 8)
	{
		if (binary[i] == 0)
			kill(server_pid, SIGUSR1);
		else if (binary[i] == 1)
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
	free(binary);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_printf("given pid is no possible");
			exit(1);
		}
		ft_printf("client : sending message\n");
		i = -1;
		while (argv[2][++i])
			send_character(server_pid, argv[2][i]);
	}
	else
		ft_printf("Usage: ./Client <Server PID> <Message to Send>");
	return (0);
}
