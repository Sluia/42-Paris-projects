/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:50:17 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:17:58 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_dir(char	*dir)
{
	char	cwd[2048];
	char	*path;

	getcwd(cwd, 2048);
	path = ft_strjoin("OLDPWD=", cwd);
	if (!path)
		return (err(ENOMEM));
	ft_setenv(path);
	free(path);
	if (chdir(dir) == -1)
		return (err(ENOTDIR));
	getcwd(cwd, 2048);
	path = ft_strjoin("PWD=", cwd);
	if (!path)
		return (err(ENOMEM));
	ft_setenv(path);
	free(path);
	return (0);
}

int	ft_cd(char **argv)
{
	int		argc;
	char	*dir;

	argc = ft_arrlen(argv);
	if (argc == 1)
		dir = ft_getenv("HOME");
	else if (argc == 2)
		dir = argv[1];
	else
		return (err(EPERM));
	return (update_dir(dir));
}
