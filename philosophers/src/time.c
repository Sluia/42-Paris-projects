#include "../include/philosophers.h"

suseconds_t get_elapsed_time(t_data *info)
{
	gettimeofday(&info->time, NULL);
	return ((info->time.tv_sec * 1000) + 
		(info->time.tv_usec / 1000) - info->start_time);
}

void ft_usleep(suseconds_t duration, t_data *info)
{
	suseconds_t start;
	suseconds_t end;

	start = get_elapsed_time(info);
	end = start + duration;
	while (get_elapsed_time(info) < end)
		usleep(100);
}