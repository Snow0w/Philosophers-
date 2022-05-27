#include "philo.h"

int	free_threads_only(pthread_t *threads)	
{
	free(threads);
	return (1);
}

int	free_threads_mutexes(pthread_t *threads, pthread_mutex_t *mutexes)
{
	free(mutexes);
	return (free_threads_only(threads));
}

int	free_thread_mut_data(pthread_t *threads, pthread_mutex_t *mutexes, t_thread_data *big_data)
{
	free(big_data);
	return (free_threads_mutexes(threads, mutexes));
}
