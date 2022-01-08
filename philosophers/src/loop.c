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
	philo->death_status = 0;
	write_event(info, 1, philo->id);
	return (NULL);
}

/*void *check_deaths(void *th_arg)
{
	t_data *info;
	int i;

	info = (t_data *)th_arg;
	while (1)
	{
		i = 0;
		while (i < info->nb_philos)
		{
			//if (info->philos->time_last_meal + info->time_die <= info->time_now)
			//	return (0);
			i++;
		}
	}
	return (1);
}*/

int write_event(t_data *info, int id_event, int id_philo)
{
	char *str;

	if (id_event == 1)
		str = ft_strjoin_philo(ft_itoa(info->time_elapsed), ": ",
			ft_itoa(id_philo), " has taken a fork");
	if (id_event == 2)
		str = ft_strjoin_philo(ft_itoa(info->time_elapsed), ": ",
			ft_itoa(id_philo), " is eating");
	if (id_event == 3)
		str = ft_strjoin_philo(ft_itoa(info->time_elapsed), ": ",
			ft_itoa(id_philo), " is sleeping");
	if (id_event == 4)
		str = ft_strjoin_philo(ft_itoa(info->time_elapsed), ": ",
			ft_itoa(id_philo), " is thinking");
	if (id_event == 5)
		str = ft_strjoin_philo(ft_itoa(info->time_elapsed), ": ",
			ft_itoa(id_philo), " died");
	if (!str)
		return (1);
	ft_wrstr_nl(1, str);
	free(str);
	return (0);
}