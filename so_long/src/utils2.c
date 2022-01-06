#include "so_long.h"

void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_str_nl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	write_nb(int nb)
{
	long	l_nb;

	l_nb = nb;
	if (l_nb > 9)
	{
		write_nb(l_nb / 10);
		write_char((l_nb % 10) + 48);
	}
	else
		write_char(l_nb + 48);
}

void	*ft_calloc(int nb_elem, int size)
{
	void	*mem_zone;

	mem_zone = malloc(nb_elem * size);
	if (mem_zone == NULL)
		return (NULL);
	mem_zone = ft_memset(mem_zone, 0, nb_elem * size);
	return (mem_zone);
}

void	*ft_memset(void *ptr, int c, int n)
{
	unsigned char	*ptr_c;
	int				i;

	ptr_c = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		ptr_c[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
