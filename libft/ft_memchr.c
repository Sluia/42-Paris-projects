/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:15:55 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:15:56 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*ptr_c;
	size_t			i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ptr_c[i])
		{
			return ((void *)&ptr_c[i]);
		}
		i++;
	}
	return (NULL);
}
