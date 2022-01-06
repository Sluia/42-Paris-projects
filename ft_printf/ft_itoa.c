/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:16:55 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:19:59 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		get_nblen(unsigned long ulnb, int base_size)
{
	int len;

	len = 1;
	while (ulnb >= (unsigned long)base_size)
	{
		ulnb /= base_size;
		len++;
	}
	return (len);
}

char	*fill_itoa(char *str, char *base, unsigned long ulnb)
{
	int nb_len;
	int i;

	nb_len = get_nblen(ulnb, ft_strlen(base));
	str = malloc((nb_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (ulnb >= ft_strlen(base))
	{
		str[i] = base[ulnb % ft_strlen(base)];
		ulnb /= ft_strlen(base);
		i++;
	}
	str[i] = base[ulnb % ft_strlen(base)];
	return (rev_arr(str, nb_len));
}

char	*ft_itoa(int nb, char *base, t_parser *pars)
{
	char			*str;
	unsigned int	unb;

	str = NULL;
	if (nb < 0)
	{
		pars->isneg = 1;
		unb = nb * -1;
	}
	else
		unb = nb;
	str = fill_itoa(str, base, unb);
	return (str);
}

char	*ft_uitoa(unsigned int unb, char *base)
{
	char *str;

	str = NULL;
	str = fill_itoa(str, base, unb);
	return (str);
}

char	*ft_pitoa(unsigned long ulnb, char *base)
{
	char *str;

	str = NULL;
	str = fill_itoa(str, base, ulnb);
	return (str);
}
