/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:42:45 by bmayer            #+#    #+#             */
/*   Updated: 2021/10/01 11:42:46 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_3d(char ****to_free)
{
	int	i;

	if (*to_free != NULL)
	{
		i = 0;
		while ((*to_free)[i] != NULL)
		{
			ft_free_2d(&(*to_free)[i]);
			(*to_free)[i] = NULL;
			i++;
		}
		free(*to_free);
		*to_free = NULL;
	}
}
