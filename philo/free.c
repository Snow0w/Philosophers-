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

int	free_thread_mut_data(pthread_t *threads, pthread_mutex_t *mutexes,
		t_thread_data *big_data)
{
	free(big_data);
	return (free_threads_mutexes(threads, mutexes));
}

int	free_destroy_threads_mutex(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&(data->mutexes[i]));
		j++;
	}
	return (free_thread_mut_data(threads, data->mutexes, big_data));
}
int	free_after_init(pthread_t *threads, t_thread_data *big_data)
{
	pthread_mutex_destroy(&(big_data->data->mut));
	return (free_destroy_threads_mutex(big_data->data, big_data,
				threads, big_data->data->num));
}
