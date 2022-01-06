/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:33 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:34:40 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_sorted_nb(t_main *data)
{
	int		*array_nb;
	t_node	*temp;
	t_node	*node;
	int		i;

	array_nb = ft_calloc(data->nb_nb, sizeof(int));
	if (array_nb == NULL)
		end_program(data, 1);
	temp = data->a;
	i = 0;
	while (temp != NULL)
	{
		array_nb[i] = temp->nb;
		i++;
		temp = temp->next;
	}
	sort_array(array_nb, data->nb_nb);
	i = 0;
	while (i < data->nb_nb)
	{
		node = get_node_wnb(data->a, array_nb[i]);
		node->sorted_nb = i;
		i++;
	}
	free(array_nb);
}

void	sort_array(int *array_nb, int nb_nb)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < nb_nb)
	{
		j = i + 1;
		while (j < nb_nb)
		{
			if (array_nb[j] < array_nb[i])
			{
				temp = array_nb[i];
				array_nb[i] = array_nb[j];
				array_nb[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_list_sorted(t_node *top)
{
	int	previous_nb;

	previous_nb = -1;
	while (top != NULL)
	{
		if (previous_nb < top->sorted_nb)
		{
			previous_nb = top->sorted_nb;
			top = top->next;
		}
		else
			return (0);
	}
	return (1);
}
