/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:20:07 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:29:04 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_cst_strcpy(char *dest, char const *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_cst_strcat(char *dest, char const *src)
{
	size_t dest_len;
	size_t i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str_concat;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_concat = ft_calloc(len, sizeof(char));
	if (str_concat == NULL)
	{
		return (NULL);
	}
	str_concat = ft_strjoin_cst_strcpy(str_concat, str1);
	str_concat = ft_strjoin_cst_strcat(str_concat, str2);
	return (str_concat);
}
