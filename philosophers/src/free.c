#include "../include/philosophers.h"

void free_all(t_data *info)
{
	free_list(info->philos);
	free(info->mutex_forks);
}

void free_list(t_node *philos)
{
	t_node *next;

	while (philos)
	{
		next = philos->next;
		free(philos);
		philos = next;
	}
}