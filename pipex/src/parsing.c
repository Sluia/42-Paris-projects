/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:52 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:29:26 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_split_path(t_data *st, char *envp[], size_t i, size_t j)
{
	if (envp == NULL)
		call_error("Error: empty ENV variable", st);
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "PATH=", 5) == 0)
		{
			st->split = ft_split(&envp[i][5], ':');
			if (st->split == NULL)
				call_error("Error: unable to split PATH", st);
			while (st->split[j] != NULL)
			{
				st->split[j] = ft_strjoin(st->split[j], "/", 1);
				if (st->split[j] == NULL)
					call_error("Error: unable to join PATH + /", st);
				j++;
			}
		}
		i++;
	}
	if (st->split == NULL)
		call_error("Error: can't find PATH in ENV variable", st);
}

void	get_all_args(t_data *st, char *args1, char *args2)
{
	if (args1 && args2)
	{
		st->args_cmd1 = ft_split(args1, ' ');
		st->args_cmd2 = ft_split(args2, ' ');
		if (st->args_cmd1 == NULL || st->args_cmd2 == NULL)
			call_error("Error: unable to split arguments", st);
	}
	else
		call_error("Error: empty list of arguments", st);
}

char	*get_path(char **split, char **args)
{
	char	*path;
	size_t	i;

	i = 0;
	while (split[i] != NULL)
	{
		path = ft_strjoin(split[i], args[0], 0);
		if (path == NULL)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
