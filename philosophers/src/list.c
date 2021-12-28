#include "philosophers.h"

t_node *new_node(int id)
{
	t_node *new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->time_last_meal = 0;
	new_node->nb_meals = 0;
	new_node->next = NULL;
	return (new_node);
}

void add_node_front(t_node **philos, t_node *new)
{
	new->next = *philos;
	*philos = new;
}

void add_node_back(t_node **philos, t_node *new)
{
	t_node *last;

	last = get_node_wpos(*philos, get_list_length(*philos));
	if (!last)
		add_node_front(philos, new);
	else
		last->next = new;
}

t_node *get_node_wpos(t_node *philos, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		philos = philos->next;
		i++;
	}
	return (philos);
}

int get_list_length(t_node *philos)
{
	int i;

	i = 0;
	while (philos)
	{
		philos = philos->next;
		i++;
	}
	return (i);
}