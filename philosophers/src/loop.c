#include "philosophers.h"

void loop_philo(t_data *info)
{
	int i;

	pthread_create(&info->checker, NULL, check_deaths, (void *)info);
	i = 0;
	while (i < info->nb_philos)
	{
		pthread_create(&info->philos[i].th, NULL, /* func */, NULL);
	}
	pthread_join(info->checker, NULL);
}

void *check_deaths(void *th_arg)
{
	t_data *info;
	int i;

	info = (t_data *)th_arg;
	while (1)
	{
		i = 0;
		while (i < info->nb_philos)
		{
			if (info->philos->time_last_meal + info->time_eat > /* gettimeofday */)
				return (0);
			i++;
		}
	}
	return (1);
}