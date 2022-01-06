/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:14:27 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:14:28 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_el;

	new_el = ft_calloc(1, sizeof(t_list));
	if (new_el == NULL)
	{
		return (NULL);
	}
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
