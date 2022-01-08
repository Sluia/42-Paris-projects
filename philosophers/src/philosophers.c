#include "../include/philosophers.h"

/*
	memset / printf / malloc / free / write
	usleep / gettimeofday
	pthread_create / pthread_detach / pthread_join / pthread_mutex_init
		pthread_mutex_destroy / pthread_mutex_lock / pthread_mutex_unlock
	
	args:
		- numbers of philosophers
		- time to die = if doesn't start eating after starting last meal => dead
		- time to eat => time required to eat, they keep their 2 forks
		- time to sleep => time required to sleep
		- [ nb of time each philo must eat ] = optional
			=> simulation stops once all philosophers have eaten x time
	
	simulation stops when a philosopher dies
	
	microseconds < milliseconds < seconds
		1000000 < 1000 < 1
	1000000 microseconds = 1 second
		1000 microseconds = 1 millisecond
	1000 milliseconds = 1 second

	usleep = microseconds
	tv_sec = seconds
	tv_usec = microseconds
		display time with milliseconds for philosophers
	
	color text depending of the action [?]

	1 philo = 1 thread

	number of forks = number of philos

	code own usleep => default one has latency
		basic infinite loop which check with gettimeofday [?]
	
	use structure to set error message [?]

	create a thread only taking care of checking death flags for philosophers

	check return values of threads for errors [?]
*/

int main(int argc, char **argv)
{
	t_data info;
	
	if (argc == 5 || argc == 6)
	{
		init_pars(&info);
		if (parsing(&info, argc, argv))
		{
			if (init_philos(&info))
			{
				loop_philo(&info);
			}
			// free all pointers
		}
	}
	return (0);
}