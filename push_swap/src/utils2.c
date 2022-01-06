/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:56:04 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 09:56:06 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nb_items, size_t size)
{
	void	*mem_zone;

	if (nb_items == 0 || size == 0)
		return (NULL);
	mem_zone = malloc(nb_items * size);
	if (mem_zone == NULL)
		return (NULL);
	mem_zone = ft_memset(mem_zone, 0, nb_items * size);
	return (mem_zone);
}

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*ptr_c;
	size_t			i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		ptr_c[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_sign_space(int c)
{
	if (c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}
