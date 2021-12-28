#include "philosophers.h"

void *get_time(void *pars)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	while (1) // changer avec flag pour exit programme si 1 philo = mort
	{
		gettimeofday(&end, NULL);
		((t_data *)pars)->time_ms = ((end.tv_sec - start.tv_sec) * 1000) + (end.tv_usec / 1000);
	}
}