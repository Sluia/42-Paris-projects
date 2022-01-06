/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:08 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:23:15 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_main	data;

	init_st(&data);
	if (argc > 1)
	{
		parse_list(&data, argc, argv);
		add_sorted_nb(&data);
		launch_algo(&data);
		end_program(&data, 0);
	}
}

void	init_st(t_main *data)
{
	data->a = NULL;
	data->b = NULL;
	data->split_args = NULL;
	data->args_space = NULL;
}

void	end_program(t_main *data, int error)
{
	free_list(data->a);
	free_list(data->b);
	ft_free_3d(&data->split_args);
	ft_free_1d(&data->args_space);
	if (error)
	{
		write_str_nl("Error", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
