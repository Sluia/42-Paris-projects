/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:23:25 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:29:39 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_cst_strcpy(char *dest, char const *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char *substr;

	if (!str)
	{
		return (NULL);
	}
	if (ft_strlen(str) < start)
	{
		return (ft_strdup(""));
	}
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
	{
		return (NULL);
	}
	substr = ft_substr_cst_strcpy(substr, &str[start], len + 1);
	return (substr);
}
