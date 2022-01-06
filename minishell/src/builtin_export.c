/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:22:51 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 11:58:48 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *str)
{
	int	i;
	int	sep;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (g_st.envp[i])
	{
		sep = ft_strchr_int(g_st.envp[i], '=');
		if (len == sep && !ft_strncmp(str, g_st.envp[i], sep))
			return (g_st.envp[i] + sep + 1);
		i++;
	}
	return (0);
}

int	ft_setenv(char *str)
{
	extern char	**environ;
	int			i;
	int			sep;
	char		*tmp;

	i = 0;
	sep = ft_strchr_int(str, '=');
	while (sep > 0 && g_st.envp[i])
	{
		if (!ft_strncmp(g_st.envp[i], str, sep))
		{
			tmp = g_st.envp[i];
			g_st.envp[i] = ft_strdup(str);
			if (!g_st.envp[i])
				return (err(ENOMEM));
			free(tmp);
			environ = g_st.envp;
			return (0);
		}
		i++;
	}
	return (ft_putenv(str));
}

int	ft_putenv(char *var)
{
	extern char	**environ;
	char		**new_envp;
	int			old_envp_len;

	old_envp_len = ft_arrlen(g_st.envp);
	new_envp = malloc((old_envp_len + 2) * sizeof(char *));
	if (!new_envp)
		return (1);
	ft_memcpy(new_envp, g_st.envp, old_envp_len * sizeof(char *));
	new_envp[old_envp_len] = ft_strdup(var);
	new_envp[old_envp_len + 1] = 0;
	free(g_st.envp);
	g_st.envp = new_envp;
	environ = new_envp;
	return (0);
}

int	check_var(char *str)
{
	if (str && !ft_isalpha(*str))
		return (1);
	while (*str && *str != '=')
	{
		if (!(ft_isalnum(*str) || *str == '_'))
			return (1);
		str++;
	}
	return (0);
}

int	ft_export(char **argv)
{
	int	i;
	int	argc;

	i = 1;
	argc = ft_arrlen(argv);
	if (argc == 1)
		return (ft_export_display());
	while (i < argc)
	{
		if (check_var(argv[i]))
		{
			err(EPERM);
			i++;
			continue ;
		}
		ft_setenv(argv[i]);
		i++;
	}
	return (1);
}
