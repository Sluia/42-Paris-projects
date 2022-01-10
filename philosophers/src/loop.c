#include "../include/philosophers.h"

void loop_philo(t_data *info)
{
	int i;

	i = 0;
	gettimeofday(&info->time, NULL);
	pthread_create(&info->th_time, NULL, update_time, (void *)info);
	while (i < info->nb_philos)
	{
		pthread_create(&info->philos->th_philo, NULL, routine_philo, (void *)info->philos);
		info->philos = info->philos->next;
		i++;
		usleep(100);
	}
	i = 0;
	while (i < info->nb_philos)
	{
		pthread_join(info->philos->th_philo, NULL);
		info->philos = info->philos->next;
		i++;
	}
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
	write_event(info->time_elapsed, 1, philo->id);
	while (!info->death_status)
	{
		if (philo->time_last_meal + info->time_die <= info->time_elapsed)
		{
			info->death_status = philo->id;
		}
		usleep(10);
	}
	if (info->death_status == philo->id)
		write_event(info->time_elapsed, 5, philo->id);
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