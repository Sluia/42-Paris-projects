/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:45 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 09:55:46 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char const *str, char delim)
{
	char	**split;
	size_t	words;

	words = ft_split_wc(str, delim);
	if (words == 0)
		return (NULL);
	split = ft_calloc(words + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = ft_split_arr(split, str, delim);
	if (split == NULL)
		return (NULL);
	split[words] = NULL;
	return (split);
}

size_t	ft_split_wc(char const *str, char delim)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	if (str[0] && str[0] != delim)
		wc++;
	i = 0;
	while (str[i])
	{
		if ((str[i] == delim) && (str[i + 1] && str[i + 1] != delim))
			wc++;
		i++;
	}
	return (wc);
}

char	**ft_split_arr(char **split, char const *str, char delim)
{
	size_t	i;
	size_t	j;
	size_t	char_count;

	i = 0;
	j = 0;
	while (str[i])
	{
		char_count = ft_split_cc(&str[i], delim);
		if (char_count)
		{
			split[j] = ft_calloc(char_count + 1, sizeof(char));
			if (split[j] == NULL)
			{
				ft_free_2d(&split);
				return (NULL);
			}
			i += ft_strcpy_i(split[j], &str[i], char_count);
			j++;
		}
		else
			i++;
	}
	return (split);
}

size_t	ft_split_cc(char const *str, char delim)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] != delim)
	{
		count++;
		i++;
	}
	return (count);
}
