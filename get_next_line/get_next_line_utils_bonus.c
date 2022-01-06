/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:21:04 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/22 09:21:36 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		cpy_buf(char *buffer, int index, int len)
{
	int i;

	i = 0;
	while (index + i < len)
	{
		buffer[i] = buffer[index + i];
		i++;
	}
	return (i);
}

int		nl_index(char *buffer, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *src, int len)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *line, char *str2, int len)
{
	char	*to_free;
	int		line_len;
	int		i;

	if (line == NULL)
	{
		line = ft_strdup(str2, len);
		if (line == NULL)
			return (NULL);
		line[len] = '\0';
		return (line);
	}
	line_len = ft_strlen(line);
	to_free = line;
	line = ft_strdup(line, line_len + len);
	free(to_free);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (line_len + ++i < line_len + len)
		line[line_len + i] = str2[i];
	line[line_len + i] = '\0';
	return (line);
}
