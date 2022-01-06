/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:26:00 by bmayer            #+#    #+#             */
/*   Updated: 2021/01/25 16:47:06 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	int				i;
	unsigned char	*src_char;
	unsigned char	*dst_char;

	i = 0;
	src_char = (unsigned char *)src;
	dst_char = (unsigned char *)dst;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		if (src_char[i] == (unsigned char)c)
			return ((void *)(dst_char + i + 1));
		i++;
	}
	return (0);
}
