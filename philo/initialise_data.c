#include "philo.h"

int	initialise_data(t_input_data *data, t_thread_data **big_data,
		pthread_t *threads)
{
	int	i;

	data->mutexes =  malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->mutexes)
		return (free_threads_only(threads));
	*big_data = malloc(sizeof(t_thread_data) * data->num);
	if (!*big_data)
		return (free_threads_mutexes(threads, data->mutexes));
	i = 0;
	while (i < data->num)
	{
		(*big_data)[i].data = data;
		if (pthread_mutex_init(&(data->mutexes[i]), NULL))
			return (free_destroy_threads_mutex(data, *big_data, threads, i));
		i++;
	}
	if (pthread_mutex_init(&(data->mut), NULL))
		return (free_destroy_threads_mutex(data, *big_data, threads, data->num));
	return (0);
}
