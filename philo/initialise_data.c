#include "philo.h"

static int	init_cont(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads)
{
	int	i;

	if (pthread_mutex_init(&(data->flag_mut), NULL))
		return (free_first_layer2(data, big_data, threads, data->num));
	data->meal_mut = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->meal_mut)
		return (free_first_layer3(data, big_data, threads, data->num));
	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(&(data->meal_mut[i]), NULL))
			return (free_first_layer4(data, big_data, threads, i));
		i++;
	}
	return (0);
}

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
	data->last_meal = malloc(sizeof(int) * data->num);
	if (!data->last_meal)
		return (free_first_layer(data, *big_data, threads, data->num));
	return (init_cont(data, *big_data, threads));
}
