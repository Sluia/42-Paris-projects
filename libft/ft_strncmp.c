/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:21:31 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:21:33 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((str1[i] - str2[i]) == 0)
		{
			i++;
		}
		else
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}
