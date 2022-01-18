/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:55:55 by qduarte           #+#    #+#             */
/*   Updated: 2022/01/18 12:06:40 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_info(t_data *info)
{
	info->philos = NULL;
	info->mutex_forks = NULL;
	info->death_status = 0;
	info->must_eat_nb = -1;
	info->nb_done_eating = 0;
}

int	init_philos(t_data *info)
{
	t_node	*new_philo;
	int		i;

	i = 0;
	while (i < info->nb_philos)
	{
		new_philo = new_node(i + 1, info);
		if (!new_philo)
			return (0);
		add_node_back(&info->philos, new_philo);
		i++;
	}
	return (1);
}
