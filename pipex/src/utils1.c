/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:21:49 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:22:53 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

void	*ft_calloc(size_t nb_items, size_t size)
{
	void	*mem_zone;

	if (nb_items == 0 || size == 0)
		return (NULL);
	mem_zone = malloc(nb_items * size);
	if (mem_zone == NULL)
		return (NULL);
	mem_zone = ft_memset(mem_zone, 0, nb_items * size);
	return (mem_zone);
}

void	ft_free(char **to_free)
{
	if (*to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

void	ft_free_2d(char ***to_free)
{
	size_t	i;

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

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*ptr_c;
	size_t			i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		ptr_c[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
