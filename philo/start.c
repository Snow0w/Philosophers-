#include "philo.h"


int	join_philo_threads(t_input_data *data, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_join(threads[i], NULL))
			return (1); // myabe clear all ???
		i++;
	}
	return (0);
}

int	start_logic(t_input_data *data, pthread_t *threads)
{
	int				i;
	t_thread_data	*big_data;
	pthread_t		garcon;

	big_data = NULL;
	if (initialise_data(data, &big_data, threads))
		return (1);
	i = 0;
	gettimeofday(&(data->time), NULL);
	memset(data->last_meal, data->time, data->num);
	while (i < data->num)
	{
		big_data[i].cnt = i;
		if (pthread_create(&threads[i], NULL, start_thread, &big_data[i]))
			return (1); // should be wrong. Can't simple free all. Can be segv from other thgreads
		i++;
	}
	if (pthread_create(&garcon, NULL, start_garcon, data))
		return (1); // hzhzhzhzzhzhzhzhzhzh
	i = join_philo_threads(data, threads);
	//free before out
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
