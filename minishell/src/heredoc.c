/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:45:53 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/28 21:41:43 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_loop(int i, int j, int fd, char *file_name)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			return (err(EINVAL));
		if (ft_strcmp(line, g_st.list_cmd[i].list_redir[j].filename))
		{
			line = exp_vars(line);
			if (!line)
				return (err(ENOMEM));
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		else
			break ;
		free(line);
	}
	free(line);
	close(fd);
	free(g_st.list_cmd[i].list_redir[j].filename);
	g_st.list_cmd[i].list_redir[j].filename = file_name;
	return (0);
}

int	heredoc(int i, int j)
{
	char	*file_name;
	int		fd;

	file_name = ft_strjoin_free(ft_itoa(i), "_tmp", 1);
	if (!file_name)
		return (err(ENOMEM));
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		free(file_name);
		return (err(EPERM));
	}
	heredoc_loop(i, j, fd, file_name);
	return (0);
}
