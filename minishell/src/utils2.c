/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:24:46 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 14:56:54 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir(t_list *word)
{
	char	c1;
	char	c2;

	c1 = get_char(word, 0);
	c2 = 0;
	if (word->next)
		c2 = get_char(word->next, 0);
	if (!c2)
		return (-1);
	if (c1 == '<' && (c2 == ' ' || ft_isalnum(c2)))
		return (1);
	if (c1 == '>' && (c2 == ' ' || ft_isalnum(c2)))
		return (2);
	if (c1 == '<' && c2 == '<')
		return (3);
	if (c1 == '>' && c2 == '>')
		return (4);
	return (0);
}

int	get_redir2(t_list *word)
{
	char	c1;
	char	c2;

	c1 = get_char(word, 0);
	c2 = get_char(word, 1);
	if (c1 == '<' && !c2)
		return (1);
	if (c1 == '>' && !c2)
		return (2);
	if (c1 == '<' && c2 == '<')
		return (3);
	if (c1 == '>' && c2 == '>')
		return (4);
	return (0);
}

int	get_nbredir(t_list	*tmp)
{
	int	nb_redir;

	nb_redir = 0;
	while (tmp)
	{
		if (get_type(tmp) == REDIR)
			nb_redir++;
		if (get_type(tmp) == PIPE)
			break ;
		tmp = ft_lstmove(tmp, 1);
	}
	return (nb_redir);
}

int	get_nb_cmd(void)
{
	t_list	*tmp;
	int		nb_pipes;

	nb_pipes = 0;
	tmp = g_st.words;
	while (tmp)
	{
		if (get_type(tmp) == PIPE)
			nb_pipes++;
		tmp = tmp->next;
	}
	g_st.nb_cmd = nb_pipes + 1;
	return (0);
}

char	**add_arg(char	*arg, char **args)
{
	int		len;
	char	**res;
	int		i;

	i = 0;
	if (!args)
	{
		res = ft_calloc(2, sizeof(char *));
		if (!res)
			return (res);
		res[0] = arg;
		return (res);
	}
	len = ft_arrlen(args);
	res = ft_calloc(len + 2, sizeof(char *));
	if (!res)
		return (res);
	while (i < len)
	{
		res[i] = args[i];
		i++;
	}
	res[i] = arg;
	free(args);
	return (res);
}
