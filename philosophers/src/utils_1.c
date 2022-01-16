#include "../include/philosophers.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (!(str1[i] - str2[i]))
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

char *ft_strdup(char *str, int length)
{
	char *dup;

	dup = ft_calloc(length + 1, sizeof(char));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, str);
	return (dup);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strcat(char *dest, char *src)
{
	int dest_length;
	int i;

	dest_length = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}