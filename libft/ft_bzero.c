/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:58:01 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 10:58:06 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*ptr_c;
	size_t			i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		ptr_c[i] = '\0';
		i++;
	}
}
