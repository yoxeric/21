/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:47:15 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/25 16:50:58 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	philo_printf(char *s, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = ft_time();
	if (!is_dead(philo))
		printf(s, time, philo->id + 1);
	usleep(10);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (time);
}

int	take_fork(t_philo *philo)
{
	int	rfork;
	int	lfork;

	if (philo->data->nb0philos % 2)
	{
		rfork = philo->id;
		lfork = (philo->id + 1) % philo->data->nb0philos;
	}
	else
	{
		rfork = (philo->id + 1) % philo->data->nb0philos;
		lfork = philo->id;
	}
	while (!is_dead(philo))
	{
		if (pickup_fork(philo, rfork, lfork))
			break ;
		usleep(50);
	}
	return (is_dead(philo));
}

int	philo_eat(t_philo *philo)
{
	int	rfork;
	int	lfork;

	if (philo->data->nb0philos % 2)
	{
		rfork = philo->id;
		lfork = (philo->id + 1) % philo->data->nb0philos;
	}
	else
	{
		rfork = (philo->id + 1) % philo->data->nb0philos;
		lfork = philo->id;
	}
	philo->last_meal = philo_printf("%lld %d is eating\n", philo);
	ft_usleep(philo->data->time2eat, philo);
	putback_fork(philo, rfork, lfork);
	return (is_dead(philo));
}

int	philo_sleep(t_philo *philo)
{
	philo_printf("%lld %d is sleeping\n", philo);
	ft_usleep(philo->data->time2sleep, philo);
	return (is_dead(philo));
}

int	philo_think(t_philo *philo)
{
	philo_printf("%lld %d is thinking\n", philo);
	usleep(150);
	return (is_dead(philo));
}
