/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:19:19 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 16:07:53 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*result;
	int		i;

	if (!s)
		return (0);
	if (len == 0)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (0);
		*result = 0;
	}
	else
	{
		result = malloc(sizeof(char) * (len + 1));
		if (!result)
			return (0);
		while (*s && start--)
			s++;
		i = 0;
		while (*s && len--)
			result[i++] = *s++;
		result[i] = 0;
	}
	return (result);
}
