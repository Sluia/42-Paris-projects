/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:22:45 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 12:03:33 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(void)
{
	int		i;
	t_type	typ;

	i = 0;
	while (g_st.input[i])
	{
		if (g_st.input[i] == '|')
			typ = PIPE;
		else if (g_st.input[i] == '\"')
			typ = DQUOTE;
		else if (g_st.input[i] == '\'')
			typ = SQUOTE;
		else if (g_st.input[i] == '<' || g_st.input[i] == '>')
			typ = REDIR;
		else if (ft_isspace(g_st.input[i]))
			typ = WSPACE;
		else if (ft_isascii(g_st.input[i]))
			typ = ASCII;
		else
			return (err(EPERM));
		if (push_lex(i, typ))
			return (err(ENOMEM));
		i++;
	}
	return (0);
}

void	*new_lex(char *str, int nb_char, t_type type)
{
	t_lex	*res;

	res = ft_calloc(1, sizeof(t_lex));
	if (!res)
		return (0);
	res->str = ft_strndup(str, nb_char);
	if (!str)
	{
		free(res);
		return (0);
	}
	res->type = type;
	return (res);
}

void	*add_lex(char *str, int nb_char, t_type type)
{
	void	*tmp_lex;
	t_list	*tmp_lst;

	tmp_lex = new_lex(str, nb_char, type);
	if (!tmp_lex)
		return (0);
	tmp_lst = ft_lstnew(tmp_lex);
	if (!tmp_lex)
	{
		free(tmp_lex);
		return (0);
	}
	return (tmp_lst);
}

int	push_lex(int i, t_type type)
{
	void	*new_lex;

	new_lex = add_lex(&g_st.input[i], 1, type);
	if (!new_lex)
		return (1);
	ft_lstadd_back(&g_st.tokens, new_lex);
	return (0);
}
