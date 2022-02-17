#include "philo.h"

int	start_logic(t_input_data data)
{
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
	t_time			time;

	threads = (pthread_t *) malloc(sizeof(pthread_t) * data.num);
	if (!threads)
		return (1);
	mutexes = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * data.num);
	if (!mutexes)
		return (free_threads_only(threads));



	
}

int	first_parse(char **argv, int mode)
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
		data.must_eat = ft_atoi([5]);
		if (data.must_eat < 1)
			return (msg_must_eat());
	}
	data.mode = mode;
	return (start_logic(data));
}
