#include "philo.h"

int	free_threads_only(pthread_t *threads)	
{
	free(threads);
	return (1);
}
