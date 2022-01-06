/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:14 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:17:59 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **top_a, t_node **top_b)
{
	t_node	*temp;

	if (*top_b != NULL)
	{
		temp = (*top_b)->next;
		add_node_front(top_a, *top_b);
		*top_b = temp;
		write_str_nl("pa", 1);
	}
}

void	pb(t_node **top_a, t_node **top_b)
{
	t_node	*temp;

	if (*top_a != NULL)
	{
		temp = (*top_a)->next;
		add_node_front(top_b, *top_a);
		*top_a = temp;
		write_str_nl("pb", 1);
	}
}

void	ra(t_node **top_a)
{
	t_node	*last;
	t_node	*temp;

	temp = *top_a;
	last = get_node_wpos(*top_a, get_list_length(*top_a));
	*top_a = (*top_a)->next;
	last->next = temp;
	temp->next = NULL;
	write_str_nl("ra", 1);
}

void	rb(t_node **top_b)
{
	t_node	*last;
	t_node	*temp;

	temp = *top_b;
	last = get_node_wpos(*top_b, get_list_length(*top_b));
	*top_b = (*top_b)->next;
	last->next = temp;
	temp->next = NULL;
	write_str_nl("rb", 1);
}

void	rr(t_node **top_a, t_node **top_b)
{
	ra(top_a);
	rb(top_b);
}
