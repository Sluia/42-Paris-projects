/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:21:45 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:30:10 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t to_find_len;

	if (!*to_find)
	{
		return ((char *)str);
	}
	to_find_len = ft_strlen(to_find);
	i = 0;
	while (str[i])
	{
		if (!(ft_strncmp(&str[i], to_find, to_find_len))
		&& (i + to_find_len <= len))
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
