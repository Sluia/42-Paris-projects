#include "so_long.h"

int	ft_strcmp(char *str1, char *str2, int n)
{
	int	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((str1[i] - str2[i]) == 0)
			i++;
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}

char	*ft_strcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *dest, char *src, int n)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin_error(char *str1, char *str2)
{
	char	*join;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2);
	join = malloc(sizeof(char) * (len + 1));
	if (join == NULL)
	{
		write_str_nl("Error:\n-> malloc didn't work properly");
		exit(EXIT_FAILURE);
	}
	join = ft_strcpy(join, str1, len);
	join[ft_strlen(str1)] = '\0';
	return (ft_strcat(join, str2, ft_strlen(str2)));
}

int	search_char(char *str, int c)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
