#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>

typedef struct s_data
{
	int		x;
	int		someone_died;
	pthread_t	*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	int		*locks;
	int		philos;
// The number of philosophers and also the number of forks.
	int		time2die;
//(in milliseconds) If a philosopher didn’t start eating time_to_die
//milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
	int		time2eat;
//(in milliseconds): The time it takes for a philosopher to eat.
//During that time, they will need to hold two forks.
	int		time2sleep;
//(in milliseconds): The time a philosopher will spend sleeping.
	int		nb4eat;
//(optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
//times, the simulation stops. If not specified, the simulation stops when a philosopher dies
}t_data;

typedef struct s_philo
{
        int     id;
	int	last_meal;
	t_data	*data;
}t_philo;

