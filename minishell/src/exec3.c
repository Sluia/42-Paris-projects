/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:11:37 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:46:48 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	join_path(void)
{
	int	i;

	i = 0;
	while (g_st.split_path && g_st.split_path[i])
	{
		g_st.split_path[i]
			= ft_strjoin_free(g_st.split_path[i], "/", 1);
		if (!g_st.split_path[i])
			return (err(ENOMEM));
		i++;
	}
	return (0);
}

int	exec_builtin(char **argv)
{
	if (!ft_strcmp_min(argv[0], "echo"))
		return (ft_echo(argv));
	if (!ft_strcmp_min(argv[0], "cd"))
		return (ft_cd(argv));
	if (!ft_strcmp_min(argv[0], "pwd"))
		return (ft_pwd(argv));
	if (!ft_strcmp_min(argv[0], "env"))
		return (ft_env(argv));
	if (!ft_strcmp_min(argv[0], "unset"))
		return (ft_unset(argv));
	if (!ft_strcmp_min(argv[0], "export"))
		return (ft_export(argv));
	if (!ft_strcmp_min(argv[0], "exit"))
		return (ft_exit(argv));
	return (0);
}

int	is_builtin(char **argv)
{
	if (!ft_strcmp_min(argv[0], "echo") || !ft_strcmp_min(argv[0], "cd")
		|| !ft_strcmp_min(argv[0], "pwd") || !ft_strcmp_min(argv[0], "env")
		|| !ft_strcmp_min(argv[0], "unset") || !ft_strcmp_min(argv[0], "export")
		|| !ft_strcmp_min(argv[0], "exit"))
		return (1);
	return (0);
}
