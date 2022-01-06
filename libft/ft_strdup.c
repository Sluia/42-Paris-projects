/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:19:32 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:19:42 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_cst_strcpy(char *dest, char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *ptr;

	ptr = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr = ft_strdup_cst_strcpy(ptr, src);
	return (ptr);
}
