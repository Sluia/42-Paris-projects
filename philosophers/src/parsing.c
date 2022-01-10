#include "../include/philosophers.h"

int parsing(t_data *info, int argc, char **argv)
{
	long result_atoi;
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] && only_digit(argv[i]))
		{
			result_atoi = ft_atoi(argv[i]);
			// free each result_atoi
			if (result_atoi > 2147483647 || result_atoi < -2147483648)
				return (0);
			set_pars_values(info, result_atoi, i);
		}
		else
			return (0);
		i++;
	}
	if (valid_values(info))
		return (1);
	return (0);
}

int only_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

void set_pars_values(t_data *info, int nb, int i)
{
	if (i == 1)
		info->nb_philos = nb;
	if (i == 2)
		info->time_die = nb;
	if (i == 3)
		info->time_eat = nb;
	if (i == 4)
		info->time_sleep = nb;
	if (i == 5)
		info->must_eat_nb = nb;
}

int valid_values(t_data *info)
{
	if (info->nb_philos < 2 || !info->time_die || !info->must_eat_nb)
		return (0);
	return (1);
}