/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:06:17 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:26:31 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last_elem;

	last_elem = ft_lstlast(alst[0]);
	if (last_elem != NULL)
	{
		last_elem->next = new;
	}
	else
	{
		ft_lstadd_front(alst, new);
	}
}
