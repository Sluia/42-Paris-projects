/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:42:21 by bmayer            #+#    #+#             */
/*   Updated: 2021/10/01 10:42:33 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_2d(char ***to_free)
{
	int	i;

	if (*to_free != NULL)
	{
		i = 0;
		while ((*to_free)[i] != NULL)
		{
			free((*to_free)[i]);
			(*to_free)[i] = NULL;
			i++;
		}
		free(*to_free);
		*to_free = NULL;
	}
}
