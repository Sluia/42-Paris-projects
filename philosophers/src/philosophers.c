/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:01:23 by qduarte           #+#    #+#             */
/*   Updated: 2022/01/18 12:01:25 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc == 5 || argc == 6)
	{
		init_info(&info);
		if (parsing(&info, argc, argv))
		{
			if (init_philos(&info))
			{
				if (!loop_philo(&info))
					ft_wrstr_nl(1, "Error: loop");
			}
			else
				ft_wrstr_nl(1, "Error: init philos");
			free_all(&info);
		}
		else
			ft_wrstr_nl(1, "Error: parsing");
	}
	return (0);
}
