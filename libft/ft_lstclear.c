/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:06:56 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:06:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;

	current = lst[0];
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	lst[0] = NULL;
}
