/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:47 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:24:03 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *str1, char const *str2, int to_free)
{
	char	*join;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	join = ft_strdup(str1, len);
	if (to_free)
		ft_free(&str1);
	if (join == NULL)
		return (NULL);
	join = ft_strcat(join, str2, ft_strlen(str2));
	return (join);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	write_str_nl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
