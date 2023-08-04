/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:31:05 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/24 19:14:25 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	solo(t_philo *philo)
{
	philo_think(philo);
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	philo->data->locks[philo->id] = philo->id;
	printf("%lld %d has taken a fork\n", ft_time(), philo->id + 1);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	while (!is_dead(philo))
		usleep(200);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		eat_time;

	philo = (t_philo *) arg;
	eat_time = philo->data->nb0eat;
	if (philo->data->nb0philos == 1)
		solo(philo);
	else
	{
		while (eat_time--)
		{
			if (philo_think(philo))
				break ;
			if (take_fork(philo))
				break ;
			if (philo_eat(philo))
				break ;
			if (philo_sleep(philo))
				break ;
		}
	}
	free(philo);
	return (0);
}

int	philos_making_machine(t_data *data, int x)
{
	t_philo	*philo;

	while (x < data->nb0philos)
	{
		philo = (t_philo *) malloc(sizeof(t_philo));
		if (!philo)
			return (1);
		philo->data = data;
		philo->id = x;
		philo->last_meal = ft_time();
		if (pthread_create(&data->philos[x], 0, &routine, philo))
			return (1);
		usleep(data->nb0philos);
		x += 2;
	}
	return (0);
}

int	start_philos(t_data	*data)
{
	int			x;

	philos_making_machine(data, 0);
	usleep(100);
	philos_making_machine(data, 1);
	x = -1;
	while (++x < data->nb0philos)
	{
		if (pthread_join(data->philos[x], NULL))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		x;
	t_data	*data;

	x = 0;
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			printf("input error");
			return (1);
		}
		ft_time();
		data = init_data(ac, av);
		start_philos(data);
		destruction(data);
	}
	else
		printf("usage: ./philo number_of_philosophers time_to_die\
 time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (0);
}
