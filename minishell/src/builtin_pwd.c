/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:54:47 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:18:28 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **argv)
{
	char	path[2048];
	int		argc;

	argc = ft_arrlen(argv);
	if (argc != 1)
		return (err(EPERM));
	if (!getcwd(path, 2048))
		return (err(ENOENT));
	ft_printf("%s\n", path);
	return (0);
}
