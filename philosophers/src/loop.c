#include "../include/philosophers.h"

void loop_philo(t_data *info)
{
	int i;

	info->mutex_forks = ft_calloc(info->nb_philos, sizeof(pthread_mutex_t));
	// return if error
	info->fork_status = ft_calloc(info->nb_philos, sizeof(int));
	// return if error
	i = 0;
	gettimeofday(&info->time, NULL);
	pthread_create(&info->th_time, NULL, update_time, (void *)info);
	while (i < info->nb_philos)
	{
		pthread_create(&info->philos->th_philo, NULL, routine_philo, (void *)info->philos);
		info->philos = info->philos->next;
		i++;
		usleep(10);
	}
	pthread_create(&info->th_death_status, NULL, check_deaths, (void *)info);
	i = 0;
	while (i < info->nb_philos)
	{
		pthread_join(info->philos->th_philo, NULL);
		info->philos = info->philos->next;
		i++;
		usleep(100);
	}
	pthread_join(info->th_death_status, NULL);
	pthread_join(info->th_time, NULL);
}

void *routine_philo(void *th_arg)
{
	t_node *philo;
	t_data *info;

	philo = (t_node *)th_arg;
	info = (t_data *)philo->st_data;
	philo->time_last_meal = info->time_elapsed;
	philo->meals_eaten = 0;
	while (!info->death_status)
	{
		if (philo->id % 2)
			usleep(1000);
		try_eating(info, philo->id);
		break;
	}
	return (NULL);
}

void try_eating(t_data *info, int philo_id)
{
	int left_fork;
	int right_fork;

	left_fork = pick_fork(info, philo_id - 1, philo_id);
	if (philo_id == info->nb_philos)
		right_fork = pick_fork(info, 0, philo_id);
	else
		right_fork = pick_fork(info, philo_id, philo_id);
	if (left_fork && right_fork)
	{
		write_event(info->time_elapsed, 2, philo_id);
		usleep(info->time_eat * 1000);
	}
}

int pick_fork(t_data *info, int fork_id, int philo_id)
{
	pthread_mutex_lock(&info->mutex_forks[fork_id]);
	while (info->fork_status[fork_id])
	{
		if (info->death_status)
			return (0);
		usleep(10);
	}
	info->fork_status[fork_id] = 1;
	write_event(info->time_elapsed, 1, philo_id);
	pthread_mutex_unlock(&info->mutex_forks[fork_id]);
	return (1);
}

/*void drop_fork(t_data *info, int fork_id)
{
	pthread_mutex_lock(&info->mutex_forks[fork_id]);
	if (!info->death_status && !info->fork_status[fork_id])
		info->fork_status[fork_id] = 0;
	pthread_mutex_unlock(&info->mutex_forks[fork_id]);
}*/

void *check_deaths(void *th_arg)
{
	t_data *info;
	t_node *temp_philos;

	info = (t_data *)th_arg;
	temp_philos = info->philos;
	while (!info->death_status)
	{
		if (temp_philos->time_last_meal + info->time_die <= info->time_elapsed)
		{
			info->death_status = 1;
			write_event(info->time_elapsed, 5, temp_philos->id);
		}
		usleep(10);
		temp_philos = temp_philos->next;
	}
	return (NULL);
}

int write_event(suseconds_t time_elapsed, int id_event, int id_philo)
{
	char *str;

	if (id_event == 1)
		str = ft_strjoin_philo(ft_itoa(time_elapsed), ": ",
			ft_itoa(id_philo), " has taken a fork");
	if (id_event == 2)
		str = ft_strjoin_philo(ft_itoa(time_elapsed), ": ",
			ft_itoa(id_philo), " is eating");
	if (id_event == 3)
		str = ft_strjoin_philo(ft_itoa(time_elapsed), ": ",
			ft_itoa(id_philo), " is sleeping");
	if (id_event == 4)
		str = ft_strjoin_philo(ft_itoa(time_elapsed), ": ",
			ft_itoa(id_philo), " is thinking");
	if (id_event == 5)
		str = ft_strjoin_philo(ft_itoa(time_elapsed), ": ",
			ft_itoa(id_philo), " died");
	if (!str)
		return (1);
	ft_wrstr_nl(1, str);
	free(str);
	return (0);
}