#include "../include/philosophers.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void *ft_calloc(int nb_elem, int size)
{
	void *mem_zone;

	mem_zone = malloc(nb_elem * size);
	if (mem_zone == NULL)
		return (NULL);
	mem_zone = ft_memset(mem_zone, 0, nb_elem * size);
	return (mem_zone);
}

void *ft_memset(void *ptr, int c, int n)
{
	unsigned char *ptr_c;
	int i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		ptr_c[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

void ft_wrstr_nl(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

char *ft_strjoin_philo(char *str1, char *str2, char *str3, char *str4)
{
	char *join;
	int length;

	length = ft_strlen(str1) + ft_strlen(str2) +
		ft_strlen(str3) + ft_strlen(str4);
	join = ft_strdup(str1, length);
	if (!join)
		return (NULL);
	join = ft_strcat(join, str2);
	join = ft_strcat(join, str3);
	join = ft_strcat(join, str4);
	return (join);
}