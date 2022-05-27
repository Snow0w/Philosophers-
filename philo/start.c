#include "philo.h"


int	join_philo_threads(t_input_data *data, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	start_logic(t_input_data *data, pthread_t *threads)
{
	int				i;
	t_thread_data	*big_data;

	data->mutexes =  malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->mutexes)
		return (free_threads_only(threads));
	gettimeofday(&(data->time), NULL);
	i = 0;
	big_data = malloc(sizeof(t_thread_data) * data->num);
	if (!big_data)
		return (free_threads_mutexes(threads, data->mutexes));
	while (i < data->num)
	{
		big_data[i].cnt = i;
		big_data[i].data = data;
		if (pthread_create(&threads[i], NULL, start_thread, &big_data[i]))
			return (free_thread_mut_data(threads, data->mutexes, big_data));
		i++;
	}
	i = join_philo_threads(data, threads);
	return (0);
}

int	first_parse(char **argv, int mode, pthread_t *threads)
{
	t_input_data	data;

	data.num = ft_atoi(argv[1]);
	if (data.num < 1)
		return (msg_wrong_philo_num());
	data.die_time = ft_atoi(argv[2]);
	if (data.die_time < 1)
		return (msg_wrong_die_time());
	data.eat_time = ft_atoi(argv[3]);
	if (data.eat_time < 1)
		return (msg_wrong_eat_time());
	data.sleep_time = ft_atoi(argv[4]);
	if (data.sleep_time < 1)
		return (msg_wrong_sleep_time());
	if (mode)
	{
		data.must_eat = ft_atoi(argv[5]);
		if (data.must_eat < 1)
			return (msg_must_eat());
	}
	data.mode = mode;
	threads =  malloc(sizeof(pthread_t) * data.num);
	if (!threads)
		return (1);
	return (start_logic(&data, threads));
}
