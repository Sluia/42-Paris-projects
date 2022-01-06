/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:32 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:20:00 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int nb)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->nb = nb;
	new_node->sorted_nb = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_front(t_node **top, t_node *new)
{
	new->next = *top;
	*top = new;
}

void	add_node_back(t_node **top, t_node *new)
{
	t_node	*last;

	last = get_node_wpos(*top, get_list_length(*top));
	if (last == NULL)
		add_node_front(top, new);
	else
		last->next = new;
}

int	get_list_length(t_node *top)
{
	int	i;

	i = 0;
	while (top != NULL)
	{
		i++;
		top = top->next;
	}
	return (i);
}
