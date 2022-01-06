/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:33:03 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 11:44:30 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	join_word(char *str)
{
	t_list	*last;

	last = ft_lstlast(g_st.words);
	((t_lex *)last->content)->str
		= ft_strjoin_free(((t_lex *)last->content)->str, str, 1);
	free(str);
	if (!((t_lex *)last->content)->str)
		return (1);
	return (0);
}
