/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:53 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:22:48 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_list(t_main *data, int argc, char *argv[])
{
	int	i;

	data->split_args = ft_calloc(argc, sizeof(char **));
	if (data->split_args == NULL)
		end_program(data, 1);
	i = 1;
	while (i < argc)
	{
		data->args_space = ft_strjoin(" ", argv[i]);
		if (data->args_space == NULL)
			end_program(data, 1);
		data->split_args[i - 1] = ft_split(data->args_space, ' ');
		if (data->split_args[i - 1] == NULL)
			end_program(data, 1);
		ft_free_1d(&data->args_space);
		i++;
	}
	data->split_args[i - 1] = NULL;
	build_list(data);
	data->nb_nb = get_list_length(data->a);
}

void	build_list(t_main *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->split_args[i] != NULL)
	{
		j = 0;
		while (data->split_args[i][j] != NULL)
		{
			if (is_arg_valid(data->split_args[i][j]))
				build_list_2(data, i, j);
			else
				end_program(data, 1);
			j++;
		}
		i++;
	}
	if (check_duplicates(data->a))
		end_program(data, 1);
}

void	build_list_2(t_main *data, int i, int j)
{
	t_node		*new;
	long long	long_nb;

	long_nb = ft_atoi(data->split_args[i][j]);
	if (long_nb > 2147483647 || long_nb < -2147483648)
		end_program(data, 1);
	new = new_node((int)long_nb);
	if (new == NULL)
		end_program(data, 1);
	add_node_back(&data->a, new);
}

int	is_arg_valid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && !ft_is_sign_space(arg[i]))
			return (0);
		if (arg[i] == '+' || arg[i] == '-')
		{
			if (arg[i + 1] != ' ' && !ft_isdigit(arg[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_node *a)
{
	t_node	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nb == temp->nb)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}
