/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:02:53 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 12:48:20 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(void)
{
	int		i;
	t_list	*tmp;
	t_type	prev;
	t_type	curr;

	prev = WSPACE;
	tmp = g_st.tokens;
	while (tmp)
	{
		curr = get_type(tmp);
		i = parse_type(tmp, curr, prev);
		if (i < 0)
			return (err(-i));
		tmp = ft_lstmove(tmp, i);
		prev = curr;
	}
	return (0);
}

int	parse_ascii(t_list *token, t_type	prev)
{
	char	*str;
	t_list	*tmp;
	int		nb_char;

	tmp = token;
	nb_char = 0;
	if (is_tilde(tmp))
		return (parse_tilde());
	while (tmp)
	{
		if (get_char(tmp, 0) == ';' || get_char(tmp, 0) == '\\')
			return (-EPERM);
		if (ft_isascii(get_char(tmp, 0)) && !(ft_invascii(get_char(tmp, 0))))
			nb_char++;
		else
			break ;
		tmp = tmp->next;
	}
	str = ft_strndup_lst(token, nb_char);
	if (!str)
		return (-ENOMEM);
	if (push_word(exp_vars(str), WORD, prev))
		return (-ENOMEM);
	return (nb_char);
}

int	parse_quote(t_list *token, char quote, t_type prev)
{
	char	*str;
	t_list	*tmp;
	int		nb_char;

	tmp = token;
	nb_char = 0;
	while (1)
	{
		if (!tmp)
			return (-EPERM);
		if (get_char(tmp, 0) == quote)
			break ;
		nb_char++;
		tmp = tmp->next;
	}
	str = ft_strndup_lst(token, nb_char);
	if (!str)
		return (-ENOMEM);
	if (quote == '\"' && push_word(exp_vars(str), WORD, prev))
		return (-ENOMEM);
	if (quote == '\'' && push_word(str, WORD, prev))
		return (-ENOMEM);
	return (nb_char + 2);
}

int	parse_pipe(t_list *token)
{
	char	*str;

	if (token->next)
	{
		if (get_char(token->next, 0) == '|')
			return (-EPERM);
		str = ft_strndup_lst(token, 1);
		if (!str)
			return (-ENOMEM);
		if (push_word(str, PIPE, WSPACE))
			return (-ENOMEM);
		return (1);
	}
	return (-EPERM);
}

int	parse_redirection(t_list *token)
{
	int		type;
	int		nb_char;
	char	*str;

	nb_char = 0;
	type = get_redir(token);
	if (type == 1 || type == 2)
		nb_char = 1;
	if (type == 3 || type == 4)
		nb_char = 2;
	if (nb_char)
	{
		str = ft_strndup_lst(token, nb_char);
		if (!str)
			return (-ENOMEM);
		if (push_word(str, REDIR, WSPACE))
		{
			free (str);
			return (-ENOMEM);
		}
		return (nb_char);
	}
	return (-EPERM);
}
