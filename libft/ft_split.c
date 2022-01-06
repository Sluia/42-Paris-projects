/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:18:53 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 12:08:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_split_cst_words_count(char const *str, char delim)
{
	size_t count;

	count = 0;
	if (str[0] && str[0] != delim)
	{
		count++;
	}
	while (*str)
	{
		if (*str == delim)
		{
			count++;
		}
		str++;
	}
	return (count);
}

size_t	ft_split_cst_char_count(char const *c, char delim)
{
	size_t count;

	count = 0;
	while (*c && *c != delim)
	{
		count++;
		c++;
	}
	return (count);
}

char	**ft_split_cst_fill_arr(char **arr_str, char const *str, char delim)
{
	size_t	i;
	int		j;
	size_t	char_count;

	i = 0;
	while (*str)
	{
		if ((char_count = ft_split_cst_char_count(str, delim)))
		{
			arr_str[i] = ft_calloc(char_count + 1, sizeof(char));
			if (arr_str[i] == NULL)
				return (NULL);
			j = -1;
			while (++j < (int)char_count)
			{
				arr_str[i][j] = *str;
				str++;
			}
			arr_str[i][j] = '\0';
			i++;
		}
		else
			str++;
	}
	return (arr_str);
}

char	**ft_split(char const *str, char delim)
{
	char	**arr_str;
	size_t	words;

	words = ft_split_cst_words_count(str, delim);
	arr_str = ft_calloc(words + 1, sizeof(char *));
	if (arr_str == NULL)
	{
		return (NULL);
	}
	arr_str = ft_split_cst_fill_arr(arr_str, str, delim);
	if (arr_str == NULL)
	{
		return (NULL);
	}
	arr_str[words] = NULL;
	return (arr_str);
}
