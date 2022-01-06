/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:07:32 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/28 19:59:12 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(void)
{
	free_pipes();
	ft_free_1d(&g_st.input);
	ft_free_2d(&g_st.split_path);
	free_tokens();
	free_words();
	free_cmd();
}
