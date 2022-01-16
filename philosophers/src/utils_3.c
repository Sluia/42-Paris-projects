#include "../include/philosophers.h"

long ft_atoi(const char *str)
{
	long result;
	int i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

char *ft_itoa(long nb)
{
	char *itoa;
	int length;

	length = get_nb_length(nb, 10);
	itoa = ft_calloc(length + 1, sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[length] = '\0';
	while (nb >= 10)
	{
		itoa[length - 1] = (nb % 10) + 48;
		nb /= 10;
		length--;
	}
	itoa[length - 1] = (nb % 10) + 48;
	return (itoa);
}

int get_nb_length(long nb, int base_length)
{
	int length;

	length = 1;
	while (nb >= base_length)
	{
		nb /= base_length;
		length++;
	}
	return (length);
}