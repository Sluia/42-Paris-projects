/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:59:44 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 10:59:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_elem, size_t size)
{
	void *mem_zone;

	if (nb_elem == 0 || size == 0)
	{
		return (malloc(sizeof(char)));
	}
	mem_zone = malloc(nb_elem * size);
	if (!mem_zone)
	{
		return (NULL);
	}
	mem_zone = ft_memset(mem_zone, 0, nb_elem * size);
	return (mem_zone);
}
