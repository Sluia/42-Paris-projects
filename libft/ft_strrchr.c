/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:22:07 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:22:08 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	length;
	size_t	i;
	char	*last_occ;

	length = ft_strlen(str) + 1;
	i = 0;
	last_occ = NULL;
	while (i < length)
	{
		if (c == str[i])
		{
			last_occ = (char *)&str[i];
		}
		i++;
	}
	return (last_occ);
}
