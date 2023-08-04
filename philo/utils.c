/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:30:25 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/24 17:16:38 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	ft_isnbr(char *s)
{
	int	x;

	x = 0;
	while (s[x] && (s[x] == '-' || s[x] == '+'))
		x++;
	if (!(s[x] >= '0' && s[x] <= '9'))
		return (0);
	while (s[x])
	{
		if (!(s[x] >= '0' && s[x] <= '9'))
			return (0);
		x++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	x;

	x = 1;
	while (av[x])
	{
		if (!ft_isnbr(av[x]))
			return (1);
		if (ft_atoi(av[x]) <= 0)
			return (1);
		x++;
	}
	return (0);
}

void	ft_usleep(long long t, t_philo *philo)
{
	long long	start;

	start = ft_time();
	while (ft_time() - start <= t && !is_dead(philo))
		usleep(100);
}

long long	ft_time(void)
{
	struct timeval		t;
	static long long	start_time;
	long long			time;

	gettimeofday(&t, 0);
	if (!start_time)
		start_time = t.tv_sec * 1000 + t.tv_usec / 1000;
	time = (t.tv_sec * 1000 + t.tv_usec / 1000);
	return (time - start_time);
}
