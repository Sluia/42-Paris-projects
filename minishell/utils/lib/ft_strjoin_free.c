/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:33:42 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/23 23:43:04 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin_free(char *str1, char const *str2, int to_free)
{
	char	*join;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2);
	join = ft_strndup(str1, len);
	if (to_free)
		ft_free_1d(&str1);
	if (join == NULL)
		return (NULL);
	join = ft_strlcat_ptr(join, str2, ft_strlen(str2));
	return (join);
}
