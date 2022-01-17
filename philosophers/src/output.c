#include "../include/philosophers.h"

int write_event(t_data *info, int id_event, int id_philo)
{
	char *str;
	char *itoa_time;
	char *itoa_id;

	itoa_time = ft_itoa(get_elapsed_time(info));
	itoa_id = ft_itoa(id_philo);
	if (!itoa_time || !itoa_id)
		return (0);
	str = get_str_event(id_event, itoa_time, itoa_id);
	free(itoa_time);
	free(itoa_id);
	if (!str)
		return (0);
	pthread_mutex_lock(&info->mutex_write);
	if (!info->death_status)
		ft_wrstr_nl(1, str);
	pthread_mutex_unlock(&info->mutex_write);
	free(str);
	return (1);
}

char *get_str_event(int id_event, char *itoa_time, char *itoa_id)
{
	char *str;

	if (id_event == 1)
		str = ft_strjoin_philo(itoa_time, ": ", itoa_id, " has taken a fork");
	if (id_event == 2)
		str = ft_strjoin_philo(itoa_time, ": ", itoa_id, " is eating");
	if (id_event == 3)
		str = ft_strjoin_philo(itoa_time, ": ", itoa_id, " is sleeping");
	if (id_event == 4)
		str = ft_strjoin_philo(itoa_time, ": ", itoa_id, " is thinking");
	if (id_event == 5)
		str = ft_strjoin_philo(itoa_time, ": ", itoa_id, " died");
	return (str);
}