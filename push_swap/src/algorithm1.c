/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:01 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:12:17 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	launch_algo(t_main *data)
{
	if (data->nb_nb == 2)
		algo_2(data);
	if (data->nb_nb == 3)
		algo_3(data);
	if (data->nb_nb > 3 && data->nb_nb < 10)
		algo_small(data);
	if (data->nb_nb > 9 && data->nb_nb < 201)
		algo_big(data, 20);
	if (data->nb_nb > 200)
		algo_big(data, 50);
}

void	algo_2(t_main *data)
{
	if (is_list_sorted(data->a) == 0)
		sa(&data->a);
}

void	algo_3(t_main *data)
{
	if (is_list_sorted(data->a) == 0)
	{
		if (data->a->sorted_nb > data->a->next->sorted_nb
			&& data->a->sorted_nb < data->a->next->next->sorted_nb)
			sa(&data->a);
		if (data->a->next->sorted_nb < data->a->sorted_nb
			&& data->a->next->sorted_nb > data->a->next->next->sorted_nb)
		{
			sa(&data->a);
			rra(&data->a);
		}
		if (data->a->next->next->sorted_nb < data->a->sorted_nb
			&& data->a->next->next->sorted_nb > data->a->next->sorted_nb)
			ra(&data->a);
		if (data->a->next->next->sorted_nb < data->a->next->sorted_nb
			&& data->a->next->next->sorted_nb > data->a->sorted_nb)
		{
			sa(&data->a);
			ra(&data->a);
		}
		if (data->a->sorted_nb < data->a->next->sorted_nb
			&& data->a->sorted_nb > data->a->next->next->sorted_nb)
			rra(&data->a);
	}
}

void	algo_small(t_main *data)
{
	int	nb_nb;

	nb_nb = data->nb_nb;
	if (is_list_sorted(data->a) == 0)
	{
		while (nb_nb > 3)
		{
			pb(&data->a, &data->b);
			nb_nb--;
		}
	}
	algo_3(data);
	push_back_to_a(data);
	rotate_a(data, 0, get_pos_node(data->a, 0));
}

void	algo_big(t_main *data, int chunk_size)
{
	int	nb_chunks;
	int	chunk;

	if (is_list_sorted(data->a) == 0)
	{
		if (data->nb_nb % chunk_size != 0)
			nb_chunks = (data->nb_nb / chunk_size) + 1;
		else
			nb_chunks = (data->nb_nb / chunk_size);
		chunk = 1;
		while (chunk <= nb_chunks)
		{
			push_chunk_to_b(data, chunk, chunk_size);
			chunk++;
		}
		pa(&data->a, &data->b);
		push_back_to_a(data);
		rotate_a(data, 0, get_pos_node(data->a, 0));
	}
}
