/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:06 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:16:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **top)
{
	t_node	*temp;

	temp = (*top)->next;
	(*top)->next = (*top)->next->next;
	temp->next = *top;
	*top = temp;
	write_str_nl("sa", 1);
}

void	sb(t_node **top)
{
	t_node	*temp;

	temp = (*top)->next;
	(*top)->next = (*top)->next->next;
	temp->next = *top;
	*top = temp;
	write_str_nl("sb", 1);
}

void	ss(t_node **top_a, t_node **top_b)
{
	sa(top_a);
	sb(top_b);
}
