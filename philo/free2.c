#include "philo.h"

int	free_first_layer(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads, int i)
{
	pthread_mutex_destroy(&(data->mut));
	return (free_destroy_threads_mutex(data, big_data, threads, i));
}

int	free_first_layer2(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads, int i)
{
	pthread_mutex_destroy(&(data->flag_mut));
	return (free_first_layer(data, big_data, threads, i));
}

int	free_first_layer3(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads, int i)
{
	free(data->meal_mut);
	return (free_first_layer2(data, big_data, threads, i));
}

int	free_first_layer4(t_input_data *data, t_thread_data *big_data,
		pthread_t *threads, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&(data->meal_mut[i]));
		j++;
	}
	return (free_first_layer3(data, big_data, threads, data->num));
}
