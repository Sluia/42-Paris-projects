/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:18 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:14:09 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_nb_list(t_node *top)
{
	int	highest_nb;

	highest_nb = top->sorted_nb;
	while (top != NULL)
	{
		if (top->sorted_nb > highest_nb)
			highest_nb = top->sorted_nb;
		top = top->next;
	}
	return (highest_nb);
}

int	get_lowest_nb_list(t_node *top)
{
	int	lowest_nb;

	lowest_nb = top->sorted_nb;
	while (top != NULL)
	{
		if (top->sorted_nb < lowest_nb)
			lowest_nb = top->sorted_nb;
		top = top->next;
	}
	return (lowest_nb);
}

int	get_higher_nb_list(t_node *top, int sorted_nb)
{
	sorted_nb++;
	while (sorted_nb <= get_highest_nb_list(top))
	{
		if (get_pos_node(top, sorted_nb) != -1)
			return (sorted_nb);
		sorted_nb++;
	}
	return (-1);
}

void	push_back_to_a(t_main *data)
{
	while (data->b != NULL)
	{
		if (data->b->sorted_nb > get_highest_nb_list(data->a))
		{
			rotate_a(data, get_lowest_nb_list(data->a),
				get_pos_node(data->a, get_lowest_nb_list(data->a)));
		}
		else
		{
			rotate_a(data, get_higher_nb_list(data->a, data->b->sorted_nb),
				get_pos_node(data->a, get_higher_nb_list(data->a,
						data->b->sorted_nb)));
		}
		pa(&data->a, &data->b);
	}
}

void	rotate_a(t_main *data, int nb_list, int node_position)
{
	while (data->a->sorted_nb != nb_list)
	{
		if (node_position < get_list_length(data->a) / 2)
			ra(&data->a);
		else
			rra(&data->a);
	}
}
