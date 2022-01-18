/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deaths.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:55:06 by qduarte           #+#    #+#             */
/*   Updated: 2022/01/18 11:55:19 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*check_deaths(void *th_arg)
{
	t_data	*info;
	t_node	*temp_philos;

	info = (t_data *)th_arg;
	temp_philos = info->philos;
	while (!info->death_status && info->nb_philos != info->nb_done_eating)
	{
		if (temp_philos->time_last_meal + info->time_die
			<= get_elapsed_time(info))
		{
			write_event(info, 5, temp_philos->id);
			info->death_status = 1;
		}
		ft_usleep(1, info);
		temp_philos = temp_philos->next;
		if (!temp_philos)
			temp_philos = info->philos;
	}
	return (NULL);
}
