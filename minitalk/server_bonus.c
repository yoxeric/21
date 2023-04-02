/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:56:49 by yhachami          #+#    #+#             */
/*   Updated: 2023/03/19 08:34:53 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	decode(int *msg)
{
	unsigned char	x;
	int				n;

	n = 8;
	x = 0;
	while (--n >= 0)
		x += (msg[7 - n] * ft_power(2, n));
	return (x);
}

void	handler(int sig, siginfo_t *info, void *uc)
{
	static int		msg[8];
	static int		pid;
	static int		i;
	unsigned char	c;

	(void)(uc);
	if (!pid)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		i = 0;
	}
	if (sig == SIGUSR1)
		msg[i++] = 0;
	if (sig == SIGUSR2)
		msg[i++] = 1;
	if (i == 8)
	{
		c = decode(msg);
		write(1, &c, 1);
		i = 0;
		if (c == '\0')
			kill(pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sig_act;

	sig_act.sa_sigaction = handler;
	sig_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig_act, NULL) < 0)
		ft_printf("failed to assign handler");
	if (sigaction(SIGUSR2, &sig_act, NULL) < 0)
		ft_printf("failed to assign handler");
	ft_printf("pid = %d\n", getpid());
	ft_printf("server: wating for a client\n");
	while (1)
		pause();
	return (0);
}
