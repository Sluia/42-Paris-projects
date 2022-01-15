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
	launch_philo_threads(info->philos, 0);
	pthread_create(&info->th_death_status, NULL, check_deaths, (void *)info);
	close_philo_threads(info->philos);
	pthread_join(info->th_death_status, NULL);
	destroy_mutex(info);
	return (1);
}

void init_mutex(t_data *info)
{
	int i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_init(&info->mutex_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->mutex_write, NULL);
}

void destroy_mutex(t_data *info)
{
	int i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_destroy(&info->mutex_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->mutex_write);
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
		// ft_usleep(1, (t_data *)philos->st_data);
	}
}

void close_philo_threads(t_node *philos)
{
	while (philos)
	{
		pthread_join(philos->th_philo, NULL);
		philos = philos->next;
		usleep(10);
		// ft_usleep(1, (t_data *)philos->st_data);
	}
}

void *routine_philo(void *th_arg)
{
	t_node *philo;
	t_data *info;

	philo = (t_node *)th_arg;
	info = (t_data *)philo->info;
	philo->time_last_meal = get_elapsed_time(info);
	philo->meals_eaten = 0;
	while (!info->death_status)
	{
		try_eating(info, philo);
		if (info->must_eat_nb == philo->meals_eaten)
			break ;
		write_event(info, 3, philo->id);
		// usleep(info->time_sleep * 1000);
		ft_usleep(info->time_sleep, info);
		write_event(info, 4, philo->id);
	}
	// protect with mutex
	info->nb_done_eating++;
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
	// usleep(info->time_eat * 1000);
	ft_usleep(info->time_eat, info);
	pthread_mutex_unlock(&info->mutex_forks[right_fork]);
	pthread_mutex_unlock(&info->mutex_forks[left_fork]);
	philo->meals_eaten++;
}

void *check_deaths(void *th_arg)
{
	t_data *info;
	t_node *temp_philos;

	info = (t_data *)th_arg;
	temp_philos = info->philos;
	while (!info->death_status && info->nb_philos != info->nb_done_eating)
	{
		if (temp_philos->time_last_meal + info->time_die <= get_elapsed_time(info))
		{
			write_event(info, 5, temp_philos->id);
			info->death_status = 1;
		}
		// usleep(10);
		ft_usleep(1, info);
		temp_philos = temp_philos->next;
		if (!temp_philos)
			temp_philos = info->philos;
	}
	return (NULL);
}

int write_event(t_data *info, int id_event, int id_philo)
{
	char *str;

	if (id_event == 1)
		str = ft_strjoin_philo(ft_itoa(get_elapsed_time(info)), ": ",
			ft_itoa(id_philo), WHITE " has taken a fork" STOP);
	if (id_event == 2)
		str = ft_strjoin_philo(ft_itoa(get_elapsed_time(info)), ": ",
			ft_itoa(id_philo), YELLOW " is eating" STOP);
	if (id_event == 3)
		str = ft_strjoin_philo(ft_itoa(get_elapsed_time(info)), ": ",
			ft_itoa(id_philo), GREEN " is sleeping" STOP);
	if (id_event == 4)
		str = ft_strjoin_philo(ft_itoa(get_elapsed_time(info)), ": ",
			ft_itoa(id_philo), BLUE " is thinking" STOP);
	if (id_event == 5)
		str = ft_strjoin_philo(ft_itoa(get_elapsed_time(info)), ": ",
			ft_itoa(id_philo), RED " died" STOP);
	if (!str)
		return (1);
	pthread_mutex_lock(&info->mutex_write);
	if (!info->death_status)
		ft_wrstr_nl(1, str);
	pthread_mutex_unlock(&info->mutex_write);
	free(str);
	return (0);
}