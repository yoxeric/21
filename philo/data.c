/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:13:43 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/24 18:34:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*setup_data(t_data *data)
{
	int	x;
	int	nb;

	nb = data->nb0philos;
	data->philos = (pthread_t *) malloc(nb * sizeof(pthread_t));
	if (!data->philos)
		return (0);
	data->locks = (int *) malloc(nb * sizeof(int));
	if (!data->locks)
		return (0);
	data->forks = (pthread_mutex_t *) malloc(nb * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (0);
	x = -1;
	while (++x < nb)
	{
		pthread_mutex_init(&data->forks[x], NULL);
		data->locks[x] = -1;
	}
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	return (data);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->someone_dead = 0;
	data->nb0philos = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	data->nb0eat = -1;
	if (ac == 6)
		data->nb0eat = ft_atoi(av[5]);
	data->philos = NULL;
	data->locks = NULL;
	data->forks = NULL;
	setup_data(data);
	return (data);
}

int	destruction(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->nb0philos)
		pthread_mutex_destroy(&data->forks[x]);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	if (data->locks)
		free(data->locks);
	free(data);
	return (0);
}
