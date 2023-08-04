/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:37:31 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/25 16:49:19 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_data {
	int					nb0philos;
	int					time2die;
	int					time2eat;
	int					time2sleep;
	int					nb0eat;
	int					someone_dead;
	int					*locks;
	pthread_t			*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		print_mutex;
}		t_data;

typedef struct s_philo {
	t_data	*data;
	int		id;
	int		nb0meal;
	int		last_meal;
}	t_philo;

int			ft_atoi(const char *str);
int			ft_isnbr(char *s);
int			check_args(char **av);
long long	ft_time(void);
void		ft_usleep(long long t, t_philo *philo);
int			is_dead(t_philo *philo);
long long	philo_printf(char *s, t_philo *philo);

int			philos_making_machine(t_data *data, int x);
t_data		*init_data(int ac, char **av);
int			destruction(t_data *data);

int			pickup_fork(t_philo *philo, int rfork, int lfork);
int			putback_fork(t_philo *philo, int rfork, int lfork);
int			take_fork(t_philo *philo);
int			philo_eat(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
#endif
