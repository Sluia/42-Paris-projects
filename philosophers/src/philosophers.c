#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_data info;

	if (argc == 5 || argc == 6)
	{
		init_info(&info);
		if (parsing(&info, argc, argv))
		{
			if (init_philos(&info))
			{
				if (!loop_philo(&info))
					ft_wrstr_nl(1, "Error: loop");
			}
			else
				ft_wrstr_nl(1, "Error: init philos");
			free_all(&info);
		}
		else
			ft_wrstr_nl(1, "Error: parsing");
	}
	return (0);
}