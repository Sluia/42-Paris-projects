/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:08:28 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:27:00 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *current;
	t_list *new_elem;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	current = head;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		current->next = new_elem;
		current = new_elem;
		lst = lst->next;
	}
	return (head);
}
