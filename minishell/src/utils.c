/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:05:47 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/15 12:37:39 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	get_char(t_list *token, int i)
{
	return (((t_lex *)((t_list *)token->content))->str[i]);
}

char	*get_str(t_list *token)
{
	return (((t_lex *)((t_list *)token->content))->str);
}

t_type	get_type(t_list *token)
{
	return (((t_lex *)((t_list *)token->content))->type);
}

char	*ft_strndup_lst(t_list *token, int nb_char)
{
	char	*dup;
	int		i;

	dup = ft_calloc(nb_char + 1, sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < nb_char)
	{
		dup[i] = get_char(token, 0);
		token = token->next;
		i++;
	}
	return (dup);
}

int	ft_invascii(char c)
{
	if (ft_isspace(c)
		|| c == '\"' || c == '\'' || c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}
