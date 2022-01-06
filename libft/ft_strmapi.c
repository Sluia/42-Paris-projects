/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:21:11 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:21:12 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*str_func;
	size_t	i;

	if (!(str) || !(f))
	{
		return (NULL);
	}
	str_func = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (str_func == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		str_func[i] = f(i, str[i]);
		i++;
	}
	str_func[i] = '\0';
	return (str_func);
}
