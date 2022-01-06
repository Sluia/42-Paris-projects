/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:24:51 by bmayer            #+#    #+#             */
/*   Updated: 2021/01/25 16:47:06 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int				i;
	unsigned char	*src_char;
	unsigned char	*dst_char;

	i = 0;
	src_char = (unsigned char *)src;
	dst_char = (unsigned char *)dst;
	if (!src && !dst)
		return (dst);
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
