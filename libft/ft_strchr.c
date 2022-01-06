/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:19:14 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:19:15 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t len;
	size_t i;

	len = ft_strlen(str) + 1;
	i = 0;
	while (i < len)
	{
		if (c == str[i])
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
