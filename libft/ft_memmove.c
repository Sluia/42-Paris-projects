/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:16:52 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 12:06:52 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	int				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			dest_c[n - 1] = src_c[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			dest_c[i] = src_c[i];
	}
	return (dest);
}
