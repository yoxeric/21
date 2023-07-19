
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

long	ft_time()
{
	struct timeval	t;
	static long	start_time;
	static long	start_utime;

	gettimeofday(&t, NULL);
	if (!start_time)
	{
		start_time = t.tv_sec;
		start_utime = t.tv_usec;
	}
	//return ((t.tv_sec - start_time) * 1000);
	return (((t.tv_sec - start_time) * 1000) + ((t.tv_usec - start_utime) / 1000));
}

int	aloc_data(t_data *data, int ac, char **av)
{
	int	x;

	data->philos = ft_atoi(av[1]);
	data->time2die = ft_atoi(av[2]);
	data->time2eat = ft_atoi(av[3]);
	data->time2sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb4eat = ft_atoi(av[5]);
	data->threads = (pthread_t *) malloc (data->philos * sizeof(pthread_t));
	if (!data->threads)
		return (0);
	data->forks = (pthread_mutex_t *) malloc (data->philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	data->locks = (int *) malloc(data->philos * sizeof(int));
	if (!data->locks)
		return (1);
	x = -1;
	while (++x < data->philos)
	{
		pthread_mutex_init(&data->forks[x], NULL);
		data->locks[x] = -1;
		
	}
	pthread_mutex_init(&data->dead_mutex, NULL);
	//printf("nb of philos = %d\n", data->philos);
	//printf("time 2 die = %d\n", data->time2die);
	//printf("time 2 eat = %d\n", data->time2eat);
	//printf("time 2 sleep = %d\n", data->time2sleep);
	//printf("nb of eat = %d\n", data->nb4eat);
	return (0);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->philos = 0; 
	data->time2die = 0;
	data->time2eat = 0;
	data->time2sleep = 0;
	data->nb4eat = -1;
	data->someone_died = 0;
	data->threads = NULL;
	data->forks = NULL;
	data->locks = NULL;
	aloc_data(data, ac, av);
	return (data);
}

t_philo	*born_philo(t_data *data, int id)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->data = data;
	philo->id = id;
	philo->last_meal = 0;
	return (philo);
}

int	is_dead(t_philo *phi)
{
	if (ft_time() - (phi->last_meal) > phi->data->time2die)
	{
		pthread_mutex_lock(&phi->data->dead_mutex);
		phi->data->someone_died = 1;
		printf("[%d] %d is dead\n", ft_time(), phi->id);
		pthread_mutex_unlock(&phi->data->dead_mutex);
		return (1);
	}
	return (0);
}

int	get_fork(t_philo *phi)
{
	int	r;
	int	l;
	
	if (phi->data->philos % 2)
	{
		r = phi->id;
		l = (phi->id + 1) % phi->data->philos;
	}
	else
	{
		r = (phi->id + 1) % phi->data->philos;
		l = phi->id;
	}
	printf("[%d] %d r fork = %d | l fork = %d\n", ft_time(), phi->id, r, l);
	pthread_mutex_lock(&phi->data->forks[r]);
	pthread_mutex_lock(&phi->data->forks[l]);
	if (phi->data->locks[r] == -1 && phi->data->locks[l] == -1)
	{
		phi->data->locks[r] = phi->id;
		phi->data->locks[l] = phi->id;
		printf("[%d] %d has taken a fork\n", ft_time(), phi->id);
	}
	pthread_mutex_unlock(&phi->data->forks[r]);
	pthread_mutex_unlock(&phi->data->forks[l]);
	return (0);
}

int	wait4fork(t_philo *phi)
{
	//printf("%d time = %d\n", phi->id, ft_time());
	while (!phi->data->someone_died)
	{
		get_fork(phi);
		if (is_dead(phi))
			return (1);
		if (phi->data->locks[phi->id] == phi->id
			&& phi->data->locks[(phi->id + 1) % phi->data->philos] == phi->id)
			return (0);
		usleep(100);
	}
	return (0);
}

int	phi_eat(t_philo *phi)
{
	phi->last_meal = ft_time();
	usleep(phi->data->time2eat * 1000);
	printf("[%d] %d i am eat\n", ft_time(), phi->id);
	return (0);
}

int	phi_sleep(t_philo *phi)
{
	usleep(phi->data->time2sleep * 1000);
	printf("[%d] %d i am sleep \n", ft_time(), phi->id);
	return (0);
}

int	putback_fork(t_philo *phi)
{	
	phi->data->locks[phi->id] = -1;
	phi->data->locks[(phi->id + 1) % phi->data->philos] = -1;
	printf("[%d] %d shbeee3\n", ft_time(), phi->id);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*phi;
	int	eat_time;

	phi = (t_philo *) arg;
	eat_time = phi->data->nb4eat;
	while (eat_time-- > -10)
	{
		//printf("i am philo %d\n", phi->id);
		//printf("eat time = %d\n", eat_time);
		if (wait4fork(phi) && !phi->data->someone_died)
			break ;
		if (phi_eat(phi) && !phi->data->someone_died)
			break ;
		if (putback_fork(phi) && !phi->data->someone_died)
			break;
		if (phi_sleep(phi) && !phi->data->someone_died)
			break ;
	}
	return (arg);
}

int	start_philos(t_data *data)
{
	int		x;
	t_philo		*philo;

	x = -1;
	while (++x < data->philos)
	{
		//philo.id = x;
		philo = born_philo(data, x);
		if (!philo)
			return (1);
		if (pthread_create(data->threads + x, NULL, &routine, (void *)philo))
			return (1);
		usleep(100);
	}
	x = -1;
	while (++x < data->philos)
	{
		if (pthread_join(data->threads[x], NULL))
			return (1);
	}
	return (0);
}

int	destruction(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philos)
		pthread_mutex_destroy(&data->forks[x]);
	pthread_mutex_destroy(&data->dead_mutex);
	if (data->threads)
		free(data->threads);
	if (data->forks)
		free(data->forks);
	if (data->locks)
		free(data->locks);
	free(data);
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

int	main(int ac, char **av)
{
	int	x;
	t_data	*data;

	x = 0;
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			printf("input error\n");
			return (0);
		}
		ft_time();
		data = init_data(ac, av);
		start_philos(data);
		destruction(data);
	}
}
