/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:55 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 09:55:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	size_t		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		if (ft_isdigit(str[i]))
			result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

char	*ft_strdup(char const *src, size_t n)
{
	char	*dup;

	dup = ft_calloc(n + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup = ft_strcpy(dup, src, n);
	return (dup);
}

char	*ft_strjoin(char *str1, char const *str2)
{
	char	*join;
	size_t	len;

	len = ft_strlen(str1) + ft_strlen(str2);
	join = ft_strdup(str1, len);
	if (join == NULL)
		return (NULL);
	join = ft_strcat(join, str2, ft_strlen(str2));
	return (join);
}

void	write_str_nl(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
