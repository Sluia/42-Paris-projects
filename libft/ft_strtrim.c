/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:23:05 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:23:05 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtrim_cst_start(char const *str, char const *set, size_t str_len)
{
	size_t i;

	i = 0;
	while (i < str_len)
	{
		if (!(ft_strchr(set, str[i])))
		{
			return (i);
		}
		i++;
	}
	return (i);
}

size_t	ft_strtrim_cst_end(char const *str, char const *set, size_t str_len)
{
	size_t i;

	i = 0;
	while (i < str_len)
	{
		if (!(ft_strchr(set, str[str_len - i - 1])))
		{
			return (str_len - i);
		}
		i++;
	}
	return (str_len - i);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*str_trim;
	size_t	str_len;
	size_t	str_start;
	size_t	str_end;

	if (set == NULL)
		return (ft_strdup((char *)str));
	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	str_start = ft_strtrim_cst_start(str, set, str_len);
	str_end = ft_strtrim_cst_end(str, set, str_len);
	if (str_start >= str_end)
	{
		return (ft_strdup(""));
	}
	str_trim = ft_calloc(str_end - str_start + 2, sizeof(char));
	if (str_trim == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_trim, str + str_start, str_end - str_start + 1);
	return (str_trim);
}
