/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:42 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:20:23 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node_wpos(t_node *top, int pos)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		top = top->next;
		i++;
	}
	return (top);
}

t_node	*get_node_wnb(t_node *top, int nb)
{
	while (top != NULL)
	{
		if (top->nb == nb)
			return (top);
		top = top->next;
	}
	return (NULL);
}

int	get_pos_node(t_node *top, int sorted_nb)
{
	int	i;

	i = 0;
	while (top != NULL)
	{
		if (top->sorted_nb == sorted_nb)
			return (i);
		top = top->next;
		i++;
	}
	return (-1);
}
