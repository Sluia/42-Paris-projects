/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:15:34 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:07:18 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_var(char *str, char **argv)
{
	int		sep;
	int		i;
	int		argc;
	char	*tmp;

	i = 1;
	argc = ft_arrlen(argv);
	sep = ft_strchr_int(str, '=');
	if (sep == -1)
		tmp = str;
	else
		tmp = ft_strndup(str, sep);
	if (!tmp)
		return (-err(ENOMEM));
	while (i < argc)
	{
		if (!ft_strcmp(tmp, argv[i]))
		{
			free (tmp);
			return (1);
		}
		i++;
	}
	free (tmp);
	return (0);
}

int	find_copy_envp(char **new_envp, int len, char **var)
{
	int	i;
	int	cmp;

	i = 0;
	while (i < len)
	{
		cmp = found_var(g_st.envp[i], var);
		if (cmp < 0)
			return (1);
		if (!cmp)
		{
			*new_envp = g_st.envp[i];
			new_envp++;
		}
		else
		{
			free(g_st.envp[i]);
			g_st.envp[i] = 0;
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **argv)
{
	extern char	**environ;
	char		**new_envp;
	int			old_envp_len;
	int			argc;

	argc = ft_arrlen(argv);
	if (argc == 1)
		return (0);
	old_envp_len = ft_arrlen(g_st.envp);
	new_envp = ft_calloc(old_envp_len, sizeof(char *));
	if (!new_envp)
		return (err(ENOMEM));
	if (find_copy_envp(new_envp, old_envp_len, argv))
		return (1);
	free(g_st.envp);
	g_st.envp = new_envp;
	environ = new_envp;
	return (0);
}
