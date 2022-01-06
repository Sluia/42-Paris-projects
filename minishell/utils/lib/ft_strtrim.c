/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:19:08 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 16:07:25 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_is_set(const char str, char const *set)
{
	while (*set)
	{
		if (str == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	if (!s1)
		return (0);
	if (!set || !*set || !ft_strlen(s1))
		return (ft_strdup(s1));
	while (*s1 && ft_is_set(s1[0], set))
		s1++;
	len = ft_strlen(s1) - 1;
	while (len > 0 && ft_is_set(s1[len], set))
		len--;
	return (ft_substr((char *)s1, 0, len + 1));
}
