/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:49:20 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/25 16:49:53 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->someone_dead)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	else if (ft_time() - philo->last_meal > philo->data->time2die)
	{
		printf("%lld %d died\n", ft_time(), philo->id + 1);
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

int	pickup_fork(t_philo *philo, int rfork, int lfork)
{
	pthread_mutex_lock(&philo->data->forks[rfork]);
	pthread_mutex_lock(&philo->data->forks[lfork]);
	if (philo->data->locks[rfork] == -1 && philo->data->locks[lfork] == -1
		&& !is_dead(philo))
	{
		philo->data->locks[rfork] = philo->id;
		philo->data->locks[lfork] = philo->id;
		philo_printf("%lld %d has taken a fork\n", philo);
		pthread_mutex_unlock(&philo->data->forks[rfork]);
		pthread_mutex_unlock(&philo->data->forks[lfork]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->forks[rfork]);
	pthread_mutex_unlock(&philo->data->forks[lfork]);
	return (0);
}

int	putback_fork(t_philo *philo, int rfork, int lfork)
{
	pthread_mutex_lock(&philo->data->forks[rfork]);
	pthread_mutex_lock(&philo->data->forks[lfork]);
	philo->data->locks[rfork] = -1;
	philo->data->locks[lfork] = -1;
	pthread_mutex_unlock(&philo->data->forks[rfork]);
	pthread_mutex_unlock(&philo->data->forks[lfork]);
	return (0);
}
