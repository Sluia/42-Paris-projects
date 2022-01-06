/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:13:02 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/22 09:15:27 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_buf(char *buffer, int index)
{
	while (index < BUFFER_SIZE)
	{
		buffer[index] = '\0';
		index++;
	}
}

int		chk_buf_read(char *buffer, int *p_buf_len, char **line)
{
	if (nl_index(buffer, *p_buf_len) != -1)
	{
		*line = ft_strjoin(*line, buffer, nl_index(buffer, *p_buf_len));
		if (*line == NULL)
			return (-1);
		*p_buf_len = cpy_buf(buffer, nl_index(buffer, *p_buf_len) + 1,
				*p_buf_len);
		clear_buf(buffer, *p_buf_len);
		return (1);
	}
	*line = ft_strjoin(*line, buffer, *p_buf_len);
	if (*line == NULL)
		return (-1);
	*p_buf_len = 0;
	clear_buf(buffer, *p_buf_len);
	return (0);
}

int		to_return(char **line, int buf_len)
{
	if (buf_len == -1)
		return (-1);
	if (*line == NULL)
		*line = ft_strjoin(*line, "", 0);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_len;
	int			return_val;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (buf_len > 0)
	{
		return_val = chk_buf_read(buffer, &buf_len, line);
		if (return_val == 1 || return_val == -1)
			return (return_val);
	}
	buf_len = (int)read(fd, buffer, BUFFER_SIZE);
	while (buf_len > 0)
	{
		return_val = chk_buf_read(buffer, &buf_len, line);
		if (return_val == 1 || return_val == -1)
			return (return_val);
		buf_len = (int)read(fd, buffer, BUFFER_SIZE);
	}
	return (to_return(line, buf_len));
}
