/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:20 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:18:56 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **top_a)
{
	t_node	*last;
	t_node	*second_last;
	t_node	*temp;

	temp = *top_a;
	last = get_node_wpos(*top_a, get_list_length(*top_a));
	second_last = get_node_wpos(*top_a, get_list_length(*top_a) - 1);
	*top_a = last;
	last->next = temp;
	second_last->next = NULL;
	write_str_nl("rra", 1);
}

void	rrb(t_node **top_b)
{
	t_node	*last;
	t_node	*second_last;
	t_node	*temp;

	temp = *top_b;
	last = get_node_wpos(*top_b, get_list_length(*top_b));
	second_last = get_node_wpos(*top_b, get_list_length(*top_b) - 1);
	*top_b = last;
	last->next = temp;
	second_last->next = NULL;
	write_str_nl("rrb", 1);
}

void	rrr(t_node **top_a, t_node **top_b)
{
	rra(top_a);
	rrb(top_b);
}
