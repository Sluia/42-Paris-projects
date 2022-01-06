/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:53:52 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:16:23 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *top)
{
	t_node	*next;

	while (top)
	{
		next = top->next;
		free(top);
		top = next;
	}
}

void	ft_free_1d(char **to_free)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

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
