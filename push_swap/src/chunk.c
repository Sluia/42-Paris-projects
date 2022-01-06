/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:37 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:15:43 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_main *data, int chunk, int chunk_size)
{
	int	nb_first;
	int	nb_last;
	int	nb_in_chunk;
	int	i;

	nb_in_chunk = total_nb_chunk(data->a, chunk, chunk_size);
	i = 0;
	while (i < nb_in_chunk)
	{
		nb_first = chunk_in_list_first(data->a, chunk, chunk_size);
		nb_last = chunk_in_list_last(data->a, chunk, chunk_size);
		if (get_pos_node(data->a, nb_first) < get_list_length(data->a)
			- get_pos_node(data->a, nb_last))
		{
			while (data->a->sorted_nb != nb_first)
				ra(&data->a);
		}
		else
		{
			while (data->a->sorted_nb != nb_last)
				rra(&data->a);
		}
		pb(&data->a, &data->b);
		i++;
	}
}

int	total_nb_chunk(t_node *top, int chunk, int chunk_size)
{
	int	begin;
	int	end;
	int	count;

	begin = chunk_size * (chunk - 1);
	end = begin + (chunk_size - 1);
	count = 0;
	while (top != NULL)
	{
		if (top->sorted_nb >= begin && top->sorted_nb <= end)
			count++;
		top = top->next;
	}
	return (count);
}

int	chunk_in_list_first(t_node *top, int chunk, int chunk_size)
{
	int	begin;
	int	end;

	begin = chunk_size * (chunk - 1);
	end = begin + (chunk_size - 1);
	while (top != NULL)
	{
		if (top->sorted_nb >= begin && top->sorted_nb <= end)
			return (top->sorted_nb);
		top = top->next;
	}
	return (-1);
}

int	chunk_in_list_last(t_node *top, int chunk, int chunk_size)
{
	int	begin;
	int	end;
	int	nb;

	begin = chunk_size * (chunk - 1);
	end = begin + (chunk_size - 1);
	nb = -1;
	while (top != NULL)
	{
		if (top->sorted_nb >= begin && top->sorted_nb <= end)
			nb = top->sorted_nb;
		top = top->next;
	}
	return (nb);
}
