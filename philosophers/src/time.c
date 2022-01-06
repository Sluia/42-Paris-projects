#include "philosophers.h"

void *update_time(void *th_arg)
{
	t_data *info;
	suseconds_t start_time;

	info = (t_data *)th_arg;
	gettimeofday(&info->time, NULL);
	start_time = (info->time.tv_sec * 1000000) + info->time.tv_usec;
	while (!info->close_status)
	{
		gettimeofday(&info->time, NULL);
		info->time_elapsed =
			((info->time.tv_sec * 1000000) + info->time.tv_usec) - start_time;
		usleep(10);
	}
	return (NULL);
}

/*void ft_usleep(t_data *info, suseconds_t ms_to_wait)
{
	suseconds_t past_time;

	past_time = info->time_now * 1000;
	while ((info->time_now * 1000) - past_time < ms_to_wait)
		usleep(1000);
}*/