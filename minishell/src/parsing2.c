/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:03:08 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 19:45:45 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	push_word(char *str, t_type type, t_type prev)
{
	void	*word;

	if (type == WORD && (prev == DQUOTE || prev == SQUOTE || prev == ASCII))
		return (join_word(str));
	word = add_word(str, type);
	if (!word)
		return (1);
	ft_lstadd_back(&g_st.words, word);
	return (0);
}

void	*add_word(char *str, t_type type)
{
	t_list	*tmp_lst;
	t_lex	*tmp_lex;

	tmp_lex = ft_calloc(1, sizeof(t_lex));
	if (!tmp_lex)
		return (0);
	tmp_lex->str = str;
	tmp_lex->type = type;
	tmp_lst = ft_lstnew(tmp_lex);
	if (!tmp_lst)
	{
		free(tmp_lex);
		return (0);
	}
	return (tmp_lst);
}

int	is_tilde(t_list *tmp)
{
	if (get_char(tmp, 0) == '~' && (!tmp->next
			|| get_char(tmp->next, 0) == ' '))
		return (1);
	return (0);
}

int	parse_tilde(void)
{
	char	*res;

	res = ft_strdup(ft_getenv("HOME"));
	if (!res)
		return (-ENOMEM);
	if (push_word(res, WORD, WSPACE))
		return (-ENOMEM);
	return (2);
}

int	parse_type(t_list *tmp, t_type curr, t_type prev)
{
	int	i;

	i = 1;
	if (curr == ASCII)
		i = parse_ascii(tmp, prev);
	if (curr == PIPE)
		i = parse_pipe(tmp);
	if (curr == DQUOTE)
		i = parse_quote(tmp->next, '\"', prev);
	if (curr == SQUOTE)
		i = parse_quote(tmp->next, '\'', prev);
	if (curr == REDIR)
		i = parse_redirection(tmp);
	return (i);
}
