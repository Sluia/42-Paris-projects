#include "../include/philosophers.h"

int loop_philo(t_data *info)
{
	info->mutex_forks = ft_calloc(info->nb_philos, sizeof(pthread_mutex_t));
	if (!info->mutex_forks)
		return (0);
	init_mutex(info);
	gettimeofday(&info->time, NULL);
	info->start_time = (info->time.tv_sec * 1000) + (info->time.tv_usec / 1000);
	launch_philo_threads(info->philos, 1);
	ft_usleep(1, info);
	launch_philo_threads(info->philos, 0);
	pthread_create(&info->th_death_status, NULL, check_deaths, (void *)info);
	pthread_join(info->th_death_status, NULL);
	close_philo_threads(info->philos);
	destroy_mutex(info);
	return (1);
}

void launch_philo_threads(t_node *philos, int even)
{
	while (philos)
	{
		if (even)
		{
			if (!(philos->id % 2))
				pthread_create(&philos->th_philo, NULL,
					routine_philo, (void *)philos);
		}
		else
			if (philos->id % 2)
				pthread_create(&philos->th_philo, NULL,
					routine_philo, (void *)philos);
		philos = philos->next;
		usleep(10);
	}
}

void close_philo_threads(t_node *philos)
{
	while (philos)
	{
		pthread_join(philos->th_philo, NULL);
		philos = philos->next;
		usleep(10);
	}
}

void *routine_philo(void *th_arg)
{
	t_node *philo;
	t_data *info;

	philo = (t_node *)th_arg;
	info = (t_data *)philo->info;
	while (!info->death_status)
	{
		if (info->nb_philos > 1)
		{
			try_eating(info, philo);
			if (info->must_eat_nb == philo->meals_eaten)
				break ;
			write_event(info, 3, philo->id);
			ft_usleep(info->time_sleep, info);
			write_event(info, 4, philo->id);
		}
	}
	pthread_mutex_lock(&info->mutex_nb_done_eating);
	info->nb_done_eating++;
	pthread_mutex_unlock(&info->mutex_nb_done_eating);
	return (NULL);
}

void try_eating(t_data *info, t_node *philo)
{
	int left_fork;
	int right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % info->nb_philos;
	pthread_mutex_lock(&info->mutex_forks[left_fork]);
	write_event(info, 1, philo->id);
	pthread_mutex_lock(&info->mutex_forks[right_fork]);
	write_event(info, 1, philo->id);
	write_event(info, 2, philo->id);
	philo->time_last_meal = get_elapsed_time(info);
	ft_usleep(info->time_eat, info);
	pthread_mutex_unlock(&info->mutex_forks[right_fork]);
	pthread_mutex_unlock(&info->mutex_forks[left_fork]);
	philo->meals_eaten++;
}