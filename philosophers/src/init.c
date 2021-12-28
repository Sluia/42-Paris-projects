#include "philosophers.h"

void init_pars(t_data *info)
{
	info->philos = NULL;
	info->time_ms = -1;
	info->nb_philo = -1;
	info->time_die = -1;
	info->time_eat = -1;
	info->time_sleep = -1;
	info->must_eat_nb = -1;
}

int init_loop(t_data *info)
{
	t_node *new_philo;
	t_node *last_philo;
	int i;

	i = 0;
	while (i < info->nb_philo)
	{
		new_philo = new_node(i + 1);
		if (!new_philo)
			return (0);
		add_node_back(&info->philos, new_philo);
		i++;
	}
	last_philo = get_node_wpos(info->philos, get_list_length(info->philos));
	last_philo->next = info->philos;
	return (1);
}