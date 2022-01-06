/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:16:22 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:16:23 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*ptr_c1;
	unsigned char	*ptr_c2;
	size_t			i;

	ptr_c1 = (unsigned char *)ptr1;
	ptr_c2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (ptr_c1[i] != ptr_c2[i])
		{
			return (ptr_c1[i] - ptr_c2[i]);
		}
		i++;
	}
	return (0);
}
