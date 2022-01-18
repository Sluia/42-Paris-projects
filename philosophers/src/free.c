/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:55:35 by qduarte           #+#    #+#             */
/*   Updated: 2022/01/18 11:55:47 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_all(t_data *info)
{
	free_list(info->philos);
	free(info->mutex_forks);
}

void	free_list(t_node *philos)
{
	t_node	*next;

	while (philos)
	{
		next = philos->next;
		free(philos);
		philos = next;
	}
}
