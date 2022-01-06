/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:01:36 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/23 23:44:41 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_split_cc(char const *str, char delim)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] && str[i] != delim)
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_split_wc(char const *str, char delim)
{
	int	wc;
	int	i;

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
	int	i;
	int	j;
	int	char_count;

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
			i += ft_strlcpy_int(split[j], &str[i], char_count);
			j++;
		}
		else
			i++;
	}
	return (split);
}

char	**ft_split(char const *str, char delim)
{
	char	**split;
	int		words;

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
