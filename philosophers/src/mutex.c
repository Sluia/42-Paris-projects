/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:04:05 by qduarte           #+#    #+#             */
/*   Updated: 2022/01/18 12:04:16 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_mutex(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_init(&info->mutex_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->mutex_nb_done_eating, NULL);
	pthread_mutex_init(&info->mutex_write, NULL);
}

void	destroy_mutex(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_destroy(&info->mutex_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->mutex_nb_done_eating);
	pthread_mutex_destroy(&info->mutex_write);
}
