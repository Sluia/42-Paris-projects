#include "../include/philosophers.h"

void loop_philo(t_data *info)
{
	int i;

	i = 0;
	pthread_create(&info->th_time, NULL, update_time, (void *)info);
	usleep(10);
	while (i < info->nb_philos)
	{
		pthread_create(&info->philos->th_philo, NULL, routine_philo, (void *)info->philos);
		info->philos = info->philos->next;
		i++;
		usleep(10000);
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
	printf("id = %d - last_meal = %ld\n", philo->id, philo->time_last_meal);
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